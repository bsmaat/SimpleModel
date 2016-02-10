#ifndef DetectorHit_h 
#define DetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"
#include "G4ParticleDefinition.hh"

class DetectorHit : public G4VHit
{
	
	public:
	DetectorHit();
	DetectorHit(const DetectorHit&);
	virtual ~DetectorHit();
	
	//operators
	const DetectorHit& operator=(const DetectorHit&);
	G4int operator==(const DetectorHit&) const;
	
	inline void* operator new(size_t);
	inline void operator delete(void*);
	
	//methods from base class
	virtual void Draw();
	virtual void Print();
	
    // Set methods
    void SetTrackID  (G4int track)      { fTrackID = track; };
    void SetParentID  (G4int parent)      { fParentID = parent; };
    void SetChamberNb(G4int chamb)      { fChamberNb = chamb; };
    void SetEdep     (G4double de)      { fEdep = de; };
    void SetKE 		 (G4double ke) 		{ fKE = ke; };
    void SetPos      (G4ThreeVector xyz){ fPos = xyz; };
	void SetMom 	 (G4ThreeVector xyz){ fMom = xyz; };
	void SetParticle (G4ParticleDefinition* f) { fParticle = f; };

    // Get methods
    G4int GetTrackID() const     { return fTrackID; };
    G4int GetParentID() const     { return fParentID; };
    G4int GetChamberNb() const   { return fChamberNb; };
    G4double GetEdep() const     { return fEdep; };
    G4double GetKE() const 		 { return fKE; };
    G4ThreeVector GetPos() const { return fPos; };	
    G4ThreeVector GetMom() const { return fMom; };
    G4ParticleDefinition* GetParticle() const { return fParticle; }
    
	
	private:
	//some data members;
	G4int fTrackID, fChamberNb, fParentID;
	G4double fEdep, fKE;
	G4ThreeVector fPos, fMom;
	G4ParticleDefinition* fParticle;
	
};

//not sure about this: collection of hits?
typedef G4THitsCollection<DetectorHit> DetectorHitsCollection;

extern G4ThreadLocal G4Allocator<DetectorHit>* DetectorHitAllocator;

inline void* DetectorHit::operator new(size_t) 
{
	if(!DetectorHitAllocator)
		DetectorHitAllocator = new G4Allocator<DetectorHit>;
	return (void *) DetectorHitAllocator->MallocSingle();
}

inline void DetectorHit::operator delete(void *hit) 
{
	DetectorHitAllocator->FreeSingle((DetectorHit*) hit);
}

#endif
