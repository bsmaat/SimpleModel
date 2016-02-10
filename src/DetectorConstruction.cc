#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "SensitiveDetector.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"


//extra includes to make rotation possible
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4SDManager.hh"


DetectorConstruction::DetectorConstruction():
	G4VUserDetectorConstruction(),
	fScoringVolume(0),
	fRotationMatrix(0)
{
	fRotationMatrix = new G4RotationMatrix();
	fRotationMatrix->rotateY(0.);
	std::cout << "Constructor called!" << std::endl;
	  fDetectorMessenger = new DetectorMessenger(this);
	  //new DetectorMessenger;
	//fDetectorMessenger = new DetectorMessenger;
}

DetectorConstruction::~DetectorConstruction()
{
delete fDetectorMessenger;
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	  // Cleanup old geometry
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
	G4NistManager* nist = G4NistManager::Instance(); //nist material manager

	//envelope parameters
	G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
	G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");

	G4bool checkOverlaps = true;
	
	//World
	G4double world_sizeXY = 1.2*env_sizeXY;
	G4double world_sizeZ = 1.2*env_sizeZ;
	G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

	G4Box* solidWorld =
		new G4Box("World", //name
				  0.5*world_sizeXY,
				  0.5*world_sizeXY, //size
				  0.5*world_sizeZ);

	G4LogicalVolume* logicWorld =
		new G4LogicalVolume(solidWorld, // its solid
							world_mat,  // its material
							"World");   // its name

	G4VPhysicalVolume* physWorld =
		new G4PVPlacement(0, // no rotation
						  G4ThreeVector(), // at (0,0,0)
						  logicWorld, //its logical volume
						  "World",
						  0,
						  false,
						  0,
						  checkOverlaps);

	// Envelope
	G4Box* solidEnv =
		new G4Box("Envelope",
				  0.5*env_sizeXY,
				  0.5*env_sizeXY,
				  0.5*env_sizeZ);

	G4LogicalVolume* logicEnv =
		new G4LogicalVolume(solidEnv,
							env_mat,
							"Envelope");

	new G4PVPlacement(0,
					  G4ThreeVector(),
					  logicEnv,
					  "Envelope",
					  logicWorld,
					  false,
					  0,
					  checkOverlaps);

	// cubic bone shape

	//compact bone = 80% of bone in body
	G4Material* bone_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
	//G4ThreeVector pos_box = G4ThreeVector(0, 2*cm, -7*cm); //need to fix position

	G4ThreeVector pos_box = G4ThreeVector(0, 0, 0);

	//box shape, make it a little smaller than the water (env)
	//G4double box_x = 0.8*env_sizeXY, box_y = 0.8*env_sizeXY, box_z = 0.2*env_sizeZ;
	G4double box_x = 5.*cm, box_y = 5.*cm, box_z = 5.*cm;
	G4Box* boxBone = new G4Box("BoxBone",
							   0.5*box_x,
							   0.5*box_y,
							   0.5*box_z);

	G4LogicalVolume* logicBox =
		new G4LogicalVolume(boxBone,
							bone_mat,
							"BoxBone");

	//G4RotationMatrix* yRot = new G4RotationMatrix;
	//yRot->rotateY(M_PI/4.*rad);

	new G4PVPlacement(fRotationMatrix,
					  pos_box,
					  logicBox,
					  "BoxBone",
					  logicEnv,
					  false,
					  0,
					  checkOverlaps);
					  
	// construct sensitive detectors!
	
	G4VisAttributes * senseDetectorVisAtt = new G4VisAttributes(G4Colour::Red());
	senseDetectorVisAtt->SetForceWireframe(true);	
	G4double senseDetector_X = env_sizeXY, senseDetector_Y = env_sizeXY, 
							senseDetector_Z = 0.1*cm;
	
	G4Material* detector_mat = nist->FindOrBuildMaterial("G4_WATER");
	
	G4Box* solidDetector = new G4Box("Detector", 0.5*senseDetector_X,
									0.5*senseDetector_Y,
									0.5*senseDetector_Z);
									
	G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector, 
					detector_mat,
					"Detector");
	
	logicDetector->SetVisAttributes(senseDetectorVisAtt);
	
	G4ThreeVector pos_detector_right = G4ThreeVector(0.*cm, 0.*cm, 5.*cm);
	G4ThreeVector pos_detector_left = G4ThreeVector(0.*cm, 0.*cm, -5.*cm);
	
		new G4PVPlacement(0,
					pos_detector_left,
					logicDetector,
					"DetectorLeft",
					logicEnv,
					false,
					0,
					checkOverlaps);
					
	new G4PVPlacement(0,
					pos_detector_right,
					logicDetector,
					"DetectorRight",
					logicEnv,
					false,
					1,
					checkOverlaps);
				


	// set scoring volume as BoxBone
	//fScoringVolume = logicBox;
	
	
	return physWorld;

}

void DetectorConstruction::ConstructSDandField() 
{
	G4String detectorName = "/SenseDetector";
	SensitiveDetector* senseDetector = new SensitiveDetector(detectorName, "HitsCollection");
	SetSensitiveDetector("Detector", senseDetector, true);
	//G4SDManager* SDman = G4SDManager::GetSDMpointer();
	//SDman->AddNewDetector(senseDetector);
}

void DetectorConstruction::SetRotationAngle(G4double newValue) 
{
	std::cout << newValue << std::endl;
	*fRotationMatrix = G4RotationMatrix();  // make it unit vector
    fRotationMatrix->rotateY(newValue);
    
    // tell G4RunManager that we change the geometry
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
}
	
