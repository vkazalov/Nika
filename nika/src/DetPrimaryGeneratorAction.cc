
#include "DetPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Positron.hh"
#include "G4GenericMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "globals.hh"
#include "stdlib.h"
#include "G4PhysicalConstants.hh"
#include "G4IonTable.hh"
#include "G4GeneralParticleSource.hh"

DetPrimaryGeneratorAction::DetPrimaryGeneratorAction()
{  
	   //\/\//\\/\/\/\/\/\/\/\\//\\//\\//\\//\\/\/\/\/\/\/\/
	   //G4Random::setTheEngine(new CLHEP::RanecuEngine());
	   //G4int i = (int)(5.*G4UniformRand()*time(NULL));
	   //G4double angle = (G4UniformRand()-0.5)*sigmaAngle;
	   //G4double cosTheta = -1.0 + 2.0*G4UniformRand();
	   //G4double ZcosTheta = 0.33*time(NULL)*G4UniformRand()+(0.15*time(NULL)*twopi*G4UniformRand()-0.2);
	   //G4double phi = time(NULL)*twopi*G4UniformRand()-0.5;
       //G4double sinTheta = sqrt(1. - cosTheta*cosTheta);
	   //G4double incidentAngle = G4UniformRand() * deg;
	   //\\//\\/\\/\/\/\///////////\\/\//\/\//\/\/\/////
		//G4double EBullet=0.*keV; //Cs-137
		//G4int n_particle = 1;
        //particleGun = new G4ParticleGun(n_particle);  
		//particleGun->SetParticleEnergy(EBullet);
		//particleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
		//particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,0.)); 
		//particleGun->SetParticleMomentumDirection(G4ThreeVector(sinTheta*cos(phi),-1.*ZcosTheta,cosTheta));
        //particleGun->SetParticlePosition(G4ThreeVector(0, 4.7*cm, 0));
		//particleGun->SetParticlePosition(G4ThreeVector(0*cm, 2.5*cm, 0*cm));
		
	   	particleGun = new G4GeneralParticleSource ();	   
}
DetPrimaryGeneratorAction::~DetPrimaryGeneratorAction()
{
    delete particleGun;
}
void DetPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 
    particleGun->GeneratePrimaryVertex(anEvent);
}


