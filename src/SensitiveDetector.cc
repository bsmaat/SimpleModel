#include "G4SDManager.hh"

#include "SensitiveDetector.hh"

#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"
#include "G4VProcess.hh"

#include "ModelRunAction.hh"
#include "Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

SensitiveDetector::SensitiveDetector(const G4String& name, const G4String& hitsCollectionName) 
	: G4VSensitiveDetector(name), fHitsCollection(NULL)
{
		collectionName.insert(hitsCollectionName);
}

SensitiveDetector::~SensitiveDetector() {}

	
void SensitiveDetector::Initialize(G4HCofThisEvent* HCE) 
{
	
	std::cout << "Initialize SD" << std::endl;
	//create hits collection
	fHitsCollection = 
		new DetectorHitsCollection(SensitiveDetectorName, collectionName[0]);
		
	//add this collection in HCE
	G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	HCE->AddHitsCollection(hcID, fHitsCollection);
	
	
}

//create, fill and store the Hit objects at each step
G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist)
{
	std::cout<<"ProccessHits()"<<std::endl;
	//std::cout << "HIT" << std::	endl;
	G4double edep = aStep->GetTotalEnergyDeposit();
	//if (edep==0.) return false;
	
	DetectorHit* aHit = new DetectorHit();
	// some set methods go here
	aHit->SetTrackID(aStep->GetTrack()->GetTrackID());
	aHit->SetChamberNb(aStep->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber());
	aHit->SetEdep(edep);
	aHit->SetKE(aStep->GetTrack()->GetKineticEnergy());
	aHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
	aHit->SetMom(aStep->GetPostStepPoint()->GetMomentum());
	aHit->SetParticle(aStep->GetTrack()->GetDefinition());
	fHitsCollection->insert(aHit);
		
	//first check if track has a createprocess (see http://hypernews.slac.stanford.edu/HyperNews/geant4/get/eventtrackmanage/919/1.html) 
	if(aStep->GetPreStepPoint()->GetProcessDefinedStep()!=0)
	{
		//check to see if the step is across a boundary?
		const G4String procName = aStep->GetPreStepPoint()->GetProcessDefinedStep()->GetProcessName();
		std::cout << procName << std::endl;
		// would like to find some documentation on GetProcessName()
		if (procName == "Transportation") 
		{	
			//now I would need to check if it's a proton
			if(aHit->GetParticle()->GetParticleName() == "proton") 
			{
				aHit->Draw();
				//need to store initial data (from chamber 0) and final data from chamber 1
				WriteToFileInitial(aHit);
			}
		}
	}
	//if (aStep->GetPreStepPoint()->GetProcessDefinedStep()->GetProcessName() == "Transportation")
	//std::cout << aStep->GetPreStepPoint()->GetProcessDefinedStep()->GetProcessName() << std::endl;
	
	return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE) 
{
	std::cout<<"EndOfEvent"<<std::endl;
	//if(verboseLevel > 1) 
	{
		G4int nofHits = fHitsCollection->entries();
		G4cout << G4endl 
		       << "-------->Hits Collection: in this event they are " << nofHits 
               << " hits in the tracker chambers: " << G4endl;
		for ( G4int i=0; i<nofHits; i++ ) 
		{
			(*fHitsCollection)[i]->Print();
			//(*fHitsCollection)[i]->Draw();
		}
		//fHitsCollection->DrawAllHits();
		
	}
}

void SensitiveDetector::CreateAnalysisManager() 
{
		std::cout << "ModelRunAction()" << std::endl;
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);     

  // Create analysis manager
  // The choice of analysis technology is done via selectin of a namespace
  // in B4Analysis.hh
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;

  // Create directories 
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFirstHistoId(1);

  // Book histograms, ntuple
  //
  
  // Creating histograms
  //analysisManager->CreateH1("1","Edep in absorber", 100, 0., 800*MeV);
  //analysisManager->CreateH1("2","Edep in gap", 100, 0., 100*MeV);
  //analysisManager->CreateH1("3","trackL in absorber", 100, 0., 1*m);
  //analysisManager->CreateH1("4","trackL in gap", 100, 0., 50*cm);

  // Creating ntuple
  //
  analysisManager->CreateNtuple("Model", "Edep and TrackL");
  analysisManager->CreateNtupleDColumn("Edep");
  analysisManager->CreateNtupleDColumn("Pos");
  //analysisManager->CreateNtupleDColumn("Labs");
  //analysisManager->CreateNtupleDColumn("Lgap");
  analysisManager->FinishNtuple();
}

void SensitiveDetector::WriteToFileInitial(DetectorHit* aHit) 
{
				G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

			// I need to store initial energy, final energy, position and momentum
			// maybe there is an easier way to do this for G4ThreeVector()
			std::cout << "FILLING" << std::endl;
			analysisManager->FillNtupleDColumn(0, aHit->GetKE());
			analysisManager->FillNtupleDColumn(1, aHit->GetPos().getX());
			analysisManager->FillNtupleDColumn(2, aHit->GetPos().getY());
			analysisManager->FillNtupleDColumn(3, aHit->GetPos().getZ());
			analysisManager->FillNtupleDColumn(4, aHit->GetMom().getX());
			analysisManager->FillNtupleDColumn(5, aHit->GetMom().getY());
			analysisManager->FillNtupleDColumn(6, aHit->GetMom().getZ());
			std::cout<< aHit->GetChamberNb() << std::endl;
			analysisManager->FillNtupleIColumn(7, aHit->GetChamberNb());
			analysisManager->FillNtupleIColumn(8, aHit->GetTrackID());
			analysisManager->AddNtupleRow();
			//std::cout << "HERE!" << std::endl;
}

void SensitiveDetector::WriteToFileFinal(DetectorHit* aHit) 
{
			G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

			// I need to store initial energy, final energy, position and momentum
			// maybe there is an easier way to do this for G4ThreeVector()
			std::cout << "FILLING" << std::endl;
			analysisManager->FillNtupleDColumn(0, aHit->GetKE());
			analysisManager->FillNtupleDColumn(1, aHit->GetPos().getX());
			analysisManager->FillNtupleDColumn(2, aHit->GetPos().getY());
			analysisManager->FillNtupleDColumn(3, aHit->GetPos().getZ());
			analysisManager->FillNtupleDColumn(4, aHit->GetMom().getX());
			analysisManager->FillNtupleDColumn(5, aHit->GetMom().getY());
			analysisManager->FillNtupleDColumn(6, aHit->GetMom().getZ());
			std::cout<< aHit->GetChamberNb() << std::endl;
			analysisManager->FillNtupleIColumn(7, aHit->GetChamberNb());
			analysisManager->FillNtupleIColumn(8, aHit->GetTrackID());
			analysisManager->AddNtupleRow();
			//std::cout << "HERE!" << std::endl;
}
	
