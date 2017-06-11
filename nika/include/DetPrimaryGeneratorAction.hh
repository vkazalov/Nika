#ifndef DetPrimaryGeneratorAction_h
#define DetPrimaryGeneratorAction_h 1
   
//#include <G4VUserPrimaryGeneratorAction.hh>
#include "G4VUserPrimaryGeneratorAction.hh"   

//class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;
class DetPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
     public:
       DetPrimaryGeneratorAction();    
      ~DetPrimaryGeneratorAction();
   
     public:
       void GeneratePrimaries(G4Event*);
	   //G4double EBullet;
     private:
	      //G4ParticleGun* particleGun;
		  G4GeneralParticleSource* particleGun;
};
   
#endif