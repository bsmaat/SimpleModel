#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4UImanager.hh"
//#include "QBBC.hh"
#include "QGSP_BERT.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4RunManager.hh"
#include "G4ScoringManager.hh"

#include "Randomize.hh"

int main(int argc, char** argv)
{
	// detect interactive mode (if no arguments) and define UI session
	G4UIExecutive* ui = 0;
	if (argc == 1) {
		ui = new G4UIExecutive(argc, argv);
	}

	// Choose random engine
	G4Random::setTheEngine(new CLHEP::RanecuEngine);

	// Construct default run manager
#ifdef G4MULTITHREADED
	G4MTRunManager* runManager = new G4MTRunManager;
#else
	G4RunManager* runManager = new G4RunManager;
#endif

	//G4ScoringManager* scoringManager = G4ScoringManager::GetScoringManager();
	

	//set mandatory initialization classes
	runManager->SetUserInitialization(new DetectorConstruction());
	G4VModularPhysicsList* physicsList = new QGSP_BERT;
	physicsList->SetVerboseLevel(1);
	runManager->SetUserInitialization(physicsList);
	runManager->SetUserInitialization(new ActionInitialization());
	
	// get pointer to user interface manager
	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();
	
	UImanager->ApplyCommand("/control/execute init_vis.mac");
	ui->SessionStart();
	
	delete visManager;
	delete runManager;
	
}
