#ifndef SensitiveDetector_h
#define SensitiveDetector_h 1

#include "DetHit.hh"
#include "G4VSensitiveDetector.hh"
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

class G4Step;
class G4TouchableHistory;
class G4HCofThisEvent;


class SensitiveDetector: public G4VSensitiveDetector
{
	public:
	  SensitiveDetector(G4String name);
	  virtual ~SensitiveDetector();
	  
	  virtual void Initialize(G4HCofThisEvent*);
	  virtual G4bool ProcessHits(G4Step* astep, G4TouchableHistory*);
	  virtual void EndOfEvent(G4HCofThisEvent*);
      virtual void clear();
      virtual void DrawAll();
      virtual void PrintAll();
	  	  
	  
	private:
	  DetHitsCollection* DetCol;   
	     
     
};


#endif 