#include "DetectorHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include <iomanip>
#include <iostream>

G4ThreadLocal G4Allocator<DetectorHit>* DetectorHitAllocator=0;

DetectorHit::DetectorHit()
: G4VHit(),
  fTrackID(-1),
  fChamberNb(-1),
  fEdep(0.),
  fPos(G4ThreeVector()),
  fMom(G4ThreeVector())
  {}
  
DetectorHit::~DetectorHit() {}
 
DetectorHit::DetectorHit(const DetectorHit& right)
: G4VHit()
{
	fTrackID = right.fTrackID;
	fChamberNb = right.fChamberNb;
	fEdep = right.fEdep;
	fPos = right.fPos;
	fMom = right.fMom;
} 

const DetectorHit& DetectorHit::operator=(const DetectorHit& right)
{
	fTrackID = right.fTrackID;
	fChamberNb = right.fChamberNb;
	fEdep = right.fEdep;
	fPos = right.fPos;
	fMom = right.fMom;
	return *this;
}

G4int DetectorHit::operator==(const DetectorHit& right) const
{
	return ( this == &right ) ? 1 : 0;
}


void DetectorHit::Draw() 
{

	G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
	if(pVVisManager)
	{
		G4Circle circle(fPos);
		circle.SetScreenSize(10.);
		circle.SetFillStyle(G4Circle::filled);
		G4Colour colour(1.,0.,0.);
		G4VisAttributes attribs(colour);
		circle.SetVisAttributes(attribs);
		pVVisManager->Draw(circle);
	}
}

void DetectorHit::Print()
{
	 G4cout
     << "  trackID: " << fTrackID << " chamberNb: " << fChamberNb
     << "Edep: "
     << std::setw(7) << G4BestUnit(fEdep,"Energy")
     << " Position: "
     << std::setw(7) << G4BestUnit( fPos,"Length")
     << " Momentum: "
     << std::setw(7) << G4BestUnit( fMom,"Length")
     << " Particle: "
     << std::setw(7) << fParticle->GetParticleName()
     << G4endl;
}
