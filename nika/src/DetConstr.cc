#include "DetConstr.hh"
#include "DetEventAction.hh"


#include "SensitiveDetector.hh"
#include "DetEventAction.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"    
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
 
#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Isotope.hh"
#include "G4Element.hh"

#include "G4UnitsTable.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UnitsTable.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4SubtractionSolid.hh"

#include <stdlib.h>
#include <time.h>
#include <fstream>

G4int SpcRaw[SpcL];




DetConstr::DetConstr():G4VUserDetectorConstruction(),
world_log(0),world_phys(0),DeadLayer_log(0),DeadLayer_phys(0),
GeCr_log(0),GeCr_phys(0),CuCover_phys(0),CuCover_log(0),
CuCoverCap_phys(0),CuCoverCap_log(0),PbCap_phys(0),PbCap_log(0),
CuHolder_phys(0),CuHolder_log(0),CuHolderLow_phys(0),CuHolderLow_log(0),
CuHolderUp_phys(0),CuHolderUp_log(0),CuCryo_phys(0),CuCryo_log(0),
CuCryoLow_phys(0),CuCryoLow_log(0),CuCryoUp_phys(0),CuCryoUp_log(0),
////material
MoO3Fomos_phys(0),MoO3Fomos_log(0),Bkgrd_phys(0),Bkgrd_log(0),
BkgrdUp_phys(0),BkgrdUp_log(0),BkgrdLow_phys(0),BkgrdLow_log(0),
CuFin_phys(0),CuFin_log(0),NdOXi_phys(0),NdOXi_log(0),
CMORK_phys(0),CMORK_log(0)

{;}
DetConstr::~DetConstr()
{
  FILE *outputFile1 = fopen("test.dat", "wt");
  		
	for (G4int ii=0; ii<SpcL; ii++)
	{ 
		
		G4double ChanValKeV = ii;
		fprintf(outputFile1, " %6.1f\t", ChanValKeV );
		fprintf(outputFile1, " %6i\n", SpcRaw[ii] );
		
				
	}
   fclose(outputFile1);
   
}




G4VPhysicalVolume* DetConstr::Construct()

{
		////-----defineMaterials-----------
		G4String name, symbol;             // a=mass of a mole;
		G4double A, z, density;            // z=mean number of protons;  
		G4int nel;
		
		//G4int iz, n;                       // iz=nb of protons  in an isotope; 
                                   // n=nb of nucleons in an isotope; G4int ncomponents, natoms;
		G4double abundance, fractionmass;
		G4double temperature, pressure;

        ///oooooooooooooooooooowork materials-----oooooooooo
		G4NistManager* nist = G4NistManager::Instance();
		G4Element* elH = nist->FindOrBuildElement(1);
		G4Element* elLi = nist->FindOrBuildElement(3);
	    G4Element* elB = nist->FindOrBuildElement(5);
		G4Element* elC = nist->FindOrBuildElement(6);
		G4Element* elN = nist->FindOrBuildElement(7);
		G4Element* elO = nist->FindOrBuildElement(8);
		G4Element* elSi = nist->FindOrBuildElement(14);
		G4Element* elK = nist->FindOrBuildElement(19);
		G4Element* elCa = nist->FindOrBuildElement(20);
		G4Element* elCr = nist->FindOrBuildElement(24);
		G4Element* elMn = nist->FindOrBuildElement(25);
		G4Element* elFe = nist->FindOrBuildElement(26);
		G4Element* elNi = nist->FindOrBuildElement(28);
		G4Element* elCu = nist->FindOrBuildElement(29);
		G4Element* elGe = nist->FindOrBuildElement(32);
		G4Element* elNd = nist->FindOrBuildElement(41);
		G4Element* elMo = nist->FindOrBuildElement(42);
		G4Element* elPb = nist->FindOrBuildElement(82);
		
		G4Material* Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
		G4Material* OrgSteclo = nist->FindOrBuildMaterial("G4_PLEXIGLASS"); 
		G4Material* Copper = nist->FindOrBuildMaterial("G4_Cu"); 
		G4Material* Germanium = nist->FindOrBuildMaterial("G4_Ge");
		G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
		G4Material* Air = nist->FindOrBuildMaterial("G4_AIR");
		G4Material* NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
		G4Material* PolyBankaMat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
		
		//quartz
		G4Material* Qtz = new G4Material(name="quartz", density = 2.200*g/cm3, nel=2);
		Qtz->AddElement(elSi, 1);
		Qtz->AddElement(elO , 2);
		G4Material* SiO2   = nist->FindOrBuildMaterial("quartz");
		
		
		
		// Stainless steel (Medical Physics, Vol 25, No 10, Oct 1998)	
		G4Material* Ssteel = new G4Material(name="Stainless steel", density = 8.02*g/cm3, nel=5);
		Ssteel->AddElement(elMn, 0.02);
		Ssteel->AddElement(elSi, 0.01);
		Ssteel->AddElement(elCr, 0.19);
		Ssteel->AddElement(elNi, 0.10);
		Ssteel->AddElement(elFe, 0.68);
		// potassium dichromate 
		G4Material* PotDich = new G4Material(name="potassium dichromate", density = 2.676*g/cm3, nel=3);
		PotDich->AddElement(elK, 2);
		PotDich->AddElement(elCr,2);
		PotDich->AddElement(elO, 7);
		// lithium carbonate
		G4Material* LithCarb = new G4Material(name="lithium carbonate", density = 2.11*g/cm3, nel=3);
		LithCarb->AddElement(elLi, 2);
		LithCarb->AddElement(elC,  1);
		LithCarb->AddElement(elO,  3);
		
		// Molibdenum oxide
		G4Material* MoliOx = new G4Material(name="Molibdenum oxide", density = 4.69*g/cm3, nel=2);
		MoliOx->AddElement(elMo, 1);
		MoliOx->AddElement(elO,  3);
		
		// calcium carbonate
		G4Material* CaCarb = new G4Material(name="calcium carbonate", density = 2.74*g/cm3, nel=3);
		CaCarb->AddElement(elCa, 1);
		CaCarb->AddElement(elC,  1);
		CaCarb->AddElement(elO,  3);
		
		// calcium molibdate
		G4Material* CaMoO4 = new G4Material(name="calcium molibdate", density = 4.53*g/cm3, nel=3);
		CaMoO4->AddElement(elCa, 1);
		CaMoO4->AddElement(elMo, 1);
		CaMoO4->AddElement(elO,  4);
		
		// calcium formiate
		G4Material* CaForm = new G4Material(name="calcium formiate", density = 2.015*g/cm3, nel=4);
		CaForm->AddElement(elCa, 1);
		CaForm->AddElement(elH,  2);
		CaForm->AddElement(elC,  2);
		CaForm->AddElement(elO,  4);
		
		// Neodymium oxide
		G4Material* NdOx = new G4Material(name="Neodymium oxide", density = 7.24*g/cm3, nel=2);
		NdOx->AddElement(elNd, 2);
		NdOx->AddElement(elO,  3);
		
		///\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
		
		///volume of world
		   
		G4double world_x = 100.0*cm;
		G4double world_y = 100.0*cm;
		G4double world_z = 100.0*cm;
		G4Box* world= new G4Box("World",world_x,world_y,world_z);
		world_log = new G4LogicalVolume(world,Vacuum,"World",0,0,0);
		world_phys = new G4PVPlacement(0,G4ThreeVector(),world_log,"World",0,false,0);   
		   
		////////////
		G4double innerRadiusTub11 = 0.*mm;
		G4double outerRadiusTub11 = 32.*mm;
		G4double hightTub11 = 33.5*mm;
		G4double startAngleTub11 = 0.*deg;
		G4double spanningAngleTub11 = 360.*deg;
		G4Tubs* Tub11 = new G4Tubs("Tub11",innerRadiusTub11,outerRadiusTub11,hightTub11,startAngleTub11,spanningAngleTub11);
		////////////
		G4double innerRadiusTub12 = 0.*mm;
		G4double outerRadiusTub12 = 29.5*mm;
		G4double hightTub12 = 31.*mm;
		//G4double outerRadiusTub12 = 23.5*mm;
		//G4double hightTub12 = 25.*mm;
		G4double startAngleTub12 = 0.*deg;
		G4double spanningAngleTub12 = 360.*deg;
		G4Tubs* Tub12 = new G4Tubs("Tub12",innerRadiusTub12,outerRadiusTub12,hightTub12,startAngleTub12,spanningAngleTub12);
		/////////
		G4double innerRadiusTub13 = 0.*mm;
		G4double outerRadiusTub13 = 5.*mm;
		G4double hightTub13 = 5.0*mm;
		G4double startAngleTub13 = 0.*deg;
		G4double spanningAngleTub13 = 360.*deg;
		G4Tubs* Tub13 = new G4Tubs("Tub13",innerRadiusTub13,outerRadiusTub13,hightTub13,startAngleTub13,spanningAngleTub13);
		//////////
		G4SubtractionSolid *Vol1 =new G4SubtractionSolid("Vol1", Tub11, Tub12,0, G4ThreeVector(0.*mm,0.*mm, 0.*mm));
		G4SubtractionSolid *DeadLayer =new G4SubtractionSolid("DeadLayer", Vol1, Tub13,0, G4ThreeVector(0.*mm,0.*mm, -33.5*mm));
		//G4SubtractionSolid *DeadLayer =new G4SubtractionSolid("DeadLayer", Vol1, Tub13,0, G4ThreeVector(0.*mm,0.*mm, -29.25*mm));
		
		DeadLayer_log = new G4LogicalVolume(DeadLayer,Germanium,"DeadLayer",0,0,0); 
		G4double DeadLayer_Pos_x = 0.*mm;
		G4double DeadLayer_Pos_y = 0.*mm;
		G4double DeadLayer_Pos_z = 0.*mm;
		DeadLayer_phys = new G4PVPlacement(0,G4ThreeVector(DeadLayer_Pos_x,DeadLayer_Pos_y,DeadLayer_Pos_z),DeadLayer_log,"DeadLayer",world_log,false,0);
		
		//////////////
		G4double innerRadiusTub14 = 0.*mm;
		G4double outerRadiusTub14 = 29.5*mm;
		G4double hightTub14 = 31.*mm;
		//G4double outerRadiusTub14 = 23.5*mm;
		//G4double hightTub14 = 25.*mm;
		G4double startAngleTub14 = 0.*deg;
		G4double spanningAngleTub14 = 360.*deg;
		G4Tubs* Tub14 = new G4Tubs("Tub14",innerRadiusTub14,outerRadiusTub14,hightTub14,startAngleTub14,spanningAngleTub14);
		///////////
		G4double innerRadius15 = 0.*mm;
		G4double outerRadius15 = 5.*mm;
		G4double hight15 = 28.5*mm;
		//G4double hight15 = 24.25*mm;
		G4double startAngle15 = 0.*deg;
		G4double spanningAngle15 = 360.*deg;
		G4Tubs* Tub15 = new G4Tubs("Tub15",innerRadius15,outerRadius15,hight15,startAngle15,spanningAngle15);
		////////////
		G4SubtractionSolid *GeCr =new G4SubtractionSolid("GeCr", Tub14, Tub15,0, G4ThreeVector(0.*mm,0.*mm, -5.*mm));
		//G4SubtractionSolid *GeCr =new G4SubtractionSolid("GeCr", Tub14, Tub15,0, G4ThreeVector(0.*mm,0.*mm, -0.75*mm));
		
		GeCr_log = new G4LogicalVolume(GeCr,Germanium,"GeCr",0,0,0); 
		G4double GeCr_Pos_x = 0.*mm;
		G4double GeCr_Pos_y = 0.*mm;
		G4double GeCr_Pos_z = 0.*mm;
		GeCr_phys = new G4PVPlacement(0,G4ThreeVector(GeCr_Pos_x,GeCr_Pos_y,GeCr_Pos_z),GeCr_log,"GeCr",world_log,false,0);
		//////
		G4double innerRadiusCuCover = 32.5*mm;
		G4double outerRadiusCuCover = 33.1*mm;
		G4double hightCuCover = 34.5*mm;
		G4double startAngleCuCover = 0.*deg;
		G4double spanningAngleCuCover = 360.*deg;
		G4Tubs* CuCover = new G4Tubs("CuCover",innerRadiusCuCover,outerRadiusCuCover,hightCuCover,startAngleCuCover,spanningAngleCuCover);  
		
		CuCover_log = new G4LogicalVolume(CuCover,Copper,"CuCover",0,0,0);		
		G4double CuCover_Pos_x = 0.*mm;
		G4double CuCover_Pos_y = 0.*mm;
		G4double CuCover_Pos_z = 0.*mm;
		CuCover_phys = new G4PVPlacement(0,G4ThreeVector(CuCover_Pos_x,CuCover_Pos_y,CuCover_Pos_z),CuCover_log,"CuCover",world_log,false,0);
		//////////////////
		G4double innerRadiusCuCoverCap = 0*mm;
		G4double outerRadiusCuCoverCap = 33.1*mm;
		G4double hightCuCoverCap = 0.3*mm;
		G4double startAngleCuCoverCap = 0.*deg;
		G4double spanningAngleCuCoverCap = 360.*deg;
		G4Tubs* CuCoverCap = new G4Tubs("CuCoverCap",innerRadiusCuCoverCap,outerRadiusCuCoverCap,hightCuCoverCap,startAngleCuCoverCap,spanningAngleCuCoverCap);  
		
		CuCoverCap_log = new G4LogicalVolume(CuCoverCap,Copper,"CuCoverCap",0,0,0);		
		G4double CuCoverCap_Pos_x = 0.*mm;
		G4double CuCoverCap_Pos_y = 0.*mm;
		G4double CuCoverCap_Pos_z = 34.8*mm;
		CuCoverCap_phys = new G4PVPlacement(0,G4ThreeVector(CuCoverCap_Pos_x,CuCoverCap_Pos_y,CuCoverCap_Pos_z),CuCoverCap_log,"CuCoverCap",world_log,false,0);
		//////////////
		G4double innerRadiusPbCap = 5.*mm;
		G4double outerRadiusPbCap = 43.1*mm;
		G4double hightPbCap = 13.*mm;
		G4double startAnglePbCap = 0.*deg;
		G4double spanningAnglePbCap = 360.*deg;
		G4Tubs* PbCap = new G4Tubs("PbCap",innerRadiusPbCap,outerRadiusPbCap,hightPbCap,startAnglePbCap,spanningAnglePbCap);  
		
		PbCap_log = new G4LogicalVolume(PbCap,Lead,"PbCap",0,0,0);		
		G4double PbCap_Pos_x = 0.*mm;
		G4double PbCap_Pos_y = 0.*mm;
		G4double PbCap_Pos_z = -47.5*mm;
		PbCap_phys = new G4PVPlacement(0,G4ThreeVector(PbCap_Pos_x,PbCap_Pos_y,PbCap_Pos_z),PbCap_log,"PbCap",world_log,false,0);
		///////////////////////////
		G4double innerRadiusCuHolder = 43.1*mm;
		G4double outerRadiusCuHolder = 43.7*mm;
		G4double hightCuHolder = 48.8*mm;
		G4double startAngleCuHolder = 0.*deg;
		G4double spanningAngleCuHolder = 360.*deg;
		G4Tubs* CuHolder = new G4Tubs("CuHolder",innerRadiusCuHolder,outerRadiusCuHolder,hightCuHolder,startAngleCuHolder,spanningAngleCuHolder);  
		
		CuHolder_log = new G4LogicalVolume(CuHolder,Copper,"CuHolder",0,0,0);		
		G4double CuHolder_Pos_x = 0.*mm;
		G4double CuHolder_Pos_y = 0.*mm;
		G4double CuHolder_Pos_z = -13.*mm;
		CuHolder_phys = new G4PVPlacement(0,G4ThreeVector(CuHolder_Pos_x,CuHolder_Pos_y,CuHolder_Pos_z),CuHolder_log,"CuHolder",world_log,false,0);
		///////////////
		G4double innerRadiusCuHolderLow = 0*mm;
		G4double outerRadiusCuHolderLow = 43.7*mm;
		G4double hightCuHolderLow = 0.3*mm;
		G4double startAngleCuHolderLow = 0.*deg;
		G4double spanningAngleCuHolderLow = 360.*deg;
		G4Tubs* CuHolderLow = new G4Tubs("CuHolderLow",innerRadiusCuHolderLow,outerRadiusCuHolderLow,hightCuHolderLow,startAngleCuHolderLow,spanningAngleCuHolderLow);  
		
		CuHolderLow_log = new G4LogicalVolume(CuHolderLow,Copper,"CuHolderLow",0,0,0);		
		G4double CuHolderLow_Pos_x = 0.*mm;
		G4double CuHolderLow_Pos_y = 0.*mm;
		G4double CuHolderLow_Pos_z = 36.1*mm;
		CuHolderLow_phys = new G4PVPlacement(0,G4ThreeVector(CuHolderLow_Pos_x,CuHolderLow_Pos_y,CuHolderLow_Pos_z),CuHolderLow_log,"CuHolderLow",world_log,false,0);
		///////////
		G4double innerRadiusCuHolderUp = 0*mm;
		G4double outerRadiusCuHolderUp = 43.7*mm;
		G4double hightCuHolderUp = 0.3*mm;
		G4double startAngleCuHolderUp = 0.*deg;
		G4double spanningAngleCuHolderUp = 360.*deg;
		G4Tubs* CuHolderUp = new G4Tubs("CuHolderUp",innerRadiusCuHolderUp,outerRadiusCuHolderUp,hightCuHolderUp,startAngleCuHolderUp,spanningAngleCuHolderUp);  
		
		CuHolderUp_log = new G4LogicalVolume(CuHolderUp,Copper,"CuHolderUp",0,0,0);		
		G4double CuHolderUp_Pos_x = 0.*mm;
		G4double CuHolderUp_Pos_y = 0.*mm;
		G4double CuHolderUp_Pos_z = -62.1*mm;
		CuHolderUp_phys = new G4PVPlacement(0,G4ThreeVector(CuHolderUp_Pos_x,CuHolderUp_Pos_y,CuHolderUp_Pos_z),CuHolderUp_log,"CuHolderUp",world_log,false,0);
		///////////Cryo
		G4double innerRadiusCuCryo = 44.*mm;
		G4double outerRadiusCuCryo = 45.*mm;
		G4double hightCuCryo = 60.*mm;
		G4double startAngleCuCryo = 0.*deg;
		G4double spanningAngleCuCryo = 360.*deg;
		G4Tubs* CuCryo = new G4Tubs("CuCryo",innerRadiusCuCryo,outerRadiusCuCryo,hightCuCryo,startAngleCuCryo,spanningAngleCuCryo);  
		
		CuCryo_log = new G4LogicalVolume(CuCryo,Copper,"CuCryo",0,0,0);		
		G4double CuCryo_Pos_x = 0.*mm;
		G4double CuCryo_Pos_y = 0.*mm;
		G4double CuCryo_Pos_z = -16.6*mm;
		CuCryo_phys = new G4PVPlacement(0,G4ThreeVector(CuCryo_Pos_x,CuCryo_Pos_y,CuCryo_Pos_z),CuCryo_log,"CuCryo",world_log,false,0);
		///////////
		G4double innerRadiusCuCryoLow = 0.*mm;
		G4double outerRadiusCuCryoLow = 45.*mm;
		G4double hightCuCryoLow = 0.5*mm;
		G4double startAngleCuCryoLow = 0.*deg;
		G4double spanningAngleCuCryoLow = 360.*deg;
		G4Tubs* CuCryoLow = new G4Tubs("CuCryoLow",innerRadiusCuCryoLow,outerRadiusCuCryoLow,hightCuCryoLow,startAngleCuCryoLow,spanningAngleCuCryoLow);  
		
		CuCryoLow_log = new G4LogicalVolume(CuCryoLow,Copper,"CuCryoLow",0,0,0);		
		G4double CuCryoLow_Pos_x = 0.*mm;
		G4double CuCryoLow_Pos_y = 0.*mm;
		G4double CuCryoLow_Pos_z = 43.9*mm;
		CuCryoLow_phys = new G4PVPlacement(0,G4ThreeVector(CuCryoLow_Pos_x,CuCryoLow_Pos_y,CuCryoLow_Pos_z),CuCryoLow_log,"CuCryoLow",world_log,false,0);
		//////
		G4double innerRadiusCuCryoUp = 0.*mm;
		G4double outerRadiusCuCryoUp = 45.*mm;
		G4double hightCuCryoUp = 0.5*mm;
		G4double startAngleCuCryoUp = 0.*deg;
		G4double spanningAngleCuCryoUp = 360.*deg;
		G4Tubs* CuCryoUp = new G4Tubs("CuCryoUp",innerRadiusCuCryoUp,outerRadiusCuCryoUp,hightCuCryoUp,startAngleCuCryoUp,spanningAngleCuCryoUp);  
		
		CuCryoUp_log = new G4LogicalVolume(CuCryoUp,Copper,"CuCryoUp",0,0,0);		
		G4double CuCryoUp_Pos_x = 0.*mm;
		G4double CuCryoUp_Pos_y = 0.*mm;
		G4double CuCryoUp_Pos_z = -77.1*mm;
		CuCryoUp_phys = new G4PVPlacement(0,G4ThreeVector(CuCryoUp_Pos_x,CuCryoUp_Pos_y,CuCryoUp_Pos_z),CuCryoUp_log,"CuCryoUp",world_log,false,0);
		
			
		///////////Background/////////////
		/*G4double innerRadiusBkgrd = 46.*mm;
		G4double outerRadiusBkgrd = 60.*mm;
		G4double hightBkgrd = 62.*mm;
		G4double startAngleBkgrd = 0.*deg;
		G4double spanningAngleBkgrd = 360.*deg;
		G4Tubs* Bkgrd = new G4Tubs("Bkgrd",innerRadiusBkgrd,outerRadiusBkgrd,hightBkgrd,startAngleBkgrd,spanningAngleBkgrd);  
		
		//Bkgrd_log = new G4LogicalVolume(Bkgrd,Vacuum,"Bkgrd",0,0,0);
		Bkgrd_log = new G4LogicalVolume(Bkgrd,Air,"Bkgrd",0,0,0);		
		G4double Bkgrd_Pos_x = 0.*mm;
		G4double Bkgrd_Pos_y = 0.*mm;
		G4double Bkgrd_Pos_z = -16.6*mm;
		Bkgrd_phys = new G4PVPlacement(0,G4ThreeVector(Bkgrd_Pos_x,Bkgrd_Pos_y,Bkgrd_Pos_z),Bkgrd_log,"Bkgrd",world_log,false,0);
		
		//\/\//\/\/\/\/\/\/\/\/\/\/
		G4double innerRadiusBkgrdLow = 0.*mm;
		G4double outerRadiusBkgrdLow = 60.*mm;
		G4double hightBkgrdLow = 7*mm;
		G4double startAngleBkgrdLow = 0.*deg;
		G4double spanningAngleBkgrdLow = 360.*deg;
		G4Tubs* BkgrdLow = new G4Tubs("BkgrdLow",innerRadiusBkgrdLow,outerRadiusBkgrdLow,hightBkgrdLow,startAngleBkgrdLow,spanningAngleBkgrdLow);  
		
		//BkgrdLow_log = new G4LogicalVolume(BkgrdLow,Vacuum,"BkgrdLow",0,0,0);
		BkgrdLow_log = new G4LogicalVolume(BkgrdLow,Air,"BkgrdLow",0,0,0);		
		G4double BkgrdLow_Pos_x = 0.*mm;
		G4double BkgrdLow_Pos_y = 0.*mm;
		G4double BkgrdLow_Pos_z =52.4*mm;
		BkgrdLow_phys = new G4PVPlacement(0,G4ThreeVector(BkgrdLow_Pos_x,BkgrdLow_Pos_y,BkgrdLow_Pos_z),BkgrdLow_log,"BkgrdLow",world_log,false,0);
		//\/\/\/\/\/\/\/\/\/\/\/\/\/
		G4double innerRadiusBkgrdUp = 0.*mm;
		G4double outerRadiusBkgrdUp = 60.*mm;
		G4double hightBkgrdUp = 7*mm;
		G4double startAngleBkgrdUp = 0.*deg;
		G4double spanningAngleBkgrdUp = 360.*deg;
		G4Tubs* BkgrdUp = new G4Tubs("BkgrdUp",innerRadiusBkgrdUp,outerRadiusBkgrdUp,hightBkgrdUp,startAngleBkgrdUp,spanningAngleBkgrdUp);  
		
		//BkgrdUp_log = new G4LogicalVolume(BkgrdUp,Vacuum,"BkgrdUp",0,0,0);	
		BkgrdUp_log = new G4LogicalVolume(BkgrdUp,Air,"BkgrdUp",0,0,0);			
		G4double BkgrdUp_Pos_x = 0.*mm;
		G4double BkgrdUp_Pos_y = 0.*mm;
		G4double BkgrdUp_Pos_z = -85.6*mm;
		BkgrdUp_phys = new G4PVPlacement(0,G4ThreeVector(BkgrdUp_Pos_x,BkgrdUp_Pos_y,BkgrdUp_Pos_z),BkgrdUp_log,"BkgrdUp",world_log,false,0);*/
		
		//volume of MoO3_Fomos_May2016
		/*G4double MoO3Fomos_x = 70.*mm;
		G4double MoO3Fomos_y = 70.*mm;
		G4double MoO3Fomos_z = 6.*mm;
		G4Box* MoO3Fomos= new G4Box("MoO3Fomos",MoO3Fomos_x,MoO3Fomos_y,MoO3Fomos_z);
		MoO3Fomos_log = new G4LogicalVolume(MoO3Fomos,MoliOx,"MoO3Fomos",0,0,0);
		G4double MoO3Fomos_Pos_x = 0.*mm;
		G4double MoO3Fomos_Pos_y = 0*mm;
		G4double MoO3Fomos_Pos_z = 50.7*mm;
		G4RotationMatrix* rot1 = new G4RotationMatrix();
		rot1->rotateX(0.*deg);
		MoO3Fomos_phys = new G4PVPlacement(rot1,G4ThreeVector(MoO3Fomos_Pos_x,MoO3Fomos_Pos_y,MoO3Fomos_Pos_z),MoO3Fomos_log,"MoO3Fomos",world_log,false,0);*/
		
		//volume of Cu_finland
		/*G4double CuFin_x = 49.5*mm;
		G4double CuFin_y = 24.75*mm;
		G4double CuFin_z = 4.5*mm;
		G4Box* CuFin= new G4Box("CuFin",CuFin_x,CuFin_y,CuFin_z);
		CuFin_log = new G4LogicalVolume(CuFin,Copper,"CuFin",0,0,0);
		G4double CuFin_Pos_x = 0.*mm;
		G4double CuFin_Pos_y = 0*mm;
		G4double CuFin_Pos_z = 49.9*mm;
		G4RotationMatrix* rot1 = new G4RotationMatrix();
		rot1->rotateX(0.*deg);
		CuFin_phys = new G4PVPlacement(rot1,G4ThreeVector(CuFin_Pos_x,CuFin_Pos_y,CuFin_Pos_z),CuFin_log,"CuFin",world_log,false,0);*/
		
		//volume of Nd2O3
		/*G4double NdOXi_x = 65.*mm;
		G4double NdOXi_y = 65.*mm;
		G4double NdOXi_z = 6.*mm;
		G4Box* NdOXi= new G4Box("NdOXi",NdOXi_x,NdOXi_y,NdOXi_z);
		NdOXi_log = new G4LogicalVolume(NdOXi,NdOx,"NdOXi",0,0,0);
		G4double NdOXi_Pos_x = 0.*mm;
		G4double NdOXi_Pos_y = 0*mm;
		G4double NdOXi_Pos_z = 50.7*mm;
		G4RotationMatrix* rot1 = new G4RotationMatrix();
		rot1->rotateX(0.*deg);
		NdOXi_phys = new G4PVPlacement(rot1,G4ThreeVector(NdOXi_Pos_x,NdOXi_Pos_y,NdOXi_Pos_z),NdOXi_log,"NdOXi",world_log,false,0);*/
		
		//volume of Nd2O3
		/*G4double CMORK_x = 60.*mm;
		G4double CMORK_y = 70.*mm;
		G4double CMORK_z = 7.*mm;
		G4Box* CMORK= new G4Box("CMORK",CMORK_x,CMORK_y,CMORK_z);
		CMORK_log = new G4LogicalVolume(CMORK,CaMoO4,"CMORK",0,0,0);
		G4double CMORK_Pos_x = 0.*mm;
		G4double CMORK_Pos_y = 0*mm;
		G4double CMORK_Pos_z = 51.7*mm;
		G4RotationMatrix* rot1 = new G4RotationMatrix();
		rot1->rotateX(0.*deg);
		CMORK_phys = new G4PVPlacement(rot1,G4ThreeVector(CMORK_Pos_x,CMORK_Pos_y,CMORK_Pos_z),CMORK_log,"CMORK",world_log,false,0);*/
		//\/\/\/\/\/ Sensitive detectors\/\/\/\/\/\/\/\/\/\/
		  		  
		G4SDManager* sdman=G4SDManager::GetSDMpointer();
		G4String Det_SDname = "GeCrystall";		  
		SensitiveDetector* Det_SD = new SensitiveDetector(Det_SDname);
		sdman->AddNewDetector (Det_SD);
		GeCr_log->SetSensitiveDetector(Det_SD);
		  
		  
		  
	  
    return world_phys; 
}