#ifndef DetConstr_h
#define DetConstr_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4Tubs;
class G4Cons;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
//class DetectorMessenger;

class DetConstr : public G4VUserDetectorConstruction
{
	public:
  
    DetConstr();
    ~DetConstr();
    G4VPhysicalVolume* Construct();
	//G4VPhysicalVolume* DefineVolumes();
	//DefineMaterials();
	
	private:
    //void DefineMaterials();
    G4Box* world;
	G4Tubs* Tub11;
	G4Tubs* Tub12;
	G4Tubs* Tub13;
	G4Tubs* Tub14;
	G4Tubs* Tub15;
	//G4Torus
	//G4Tubs* stenkaSsteel;
	//G4Tubs* stenkaQuartz;
	//G4Tubs* NaIcrystall;
	//G4Cons* banka;
	//G4Cons* chrompik;
	
	
		
    G4LogicalVolume* world_log;
	G4LogicalVolume* DeadLayer_log;
    G4LogicalVolume* GeCr_log;
	G4LogicalVolume* CuCover_log;
	G4LogicalVolume* CuCoverCap_log;
	G4LogicalVolume* PbCap_log;
	G4LogicalVolume* CuHolder_log;
	G4LogicalVolume* CuHolderLow_log;
	G4LogicalVolume* CuHolderUp_log;
	G4LogicalVolume* CuCryo_log;
	G4LogicalVolume* CuCryoLow_log;
	G4LogicalVolume* CuCryoUp_log;
	G4LogicalVolume* MoO3Fomos_log;
	G4LogicalVolume* Bkgrd_log;
	G4LogicalVolume* BkgrdUp_log;
	G4LogicalVolume* BkgrdLow_log;
	G4LogicalVolume* CuFin_log;
	G4LogicalVolume* NdOXi_log;
	G4LogicalVolume* CMORK_log;
	
	// Physical volumes
    //
    G4VPhysicalVolume* world_phys;
	G4VPhysicalVolume* DeadLayer_phys;
    G4VPhysicalVolume* GeCr_phys;
	G4VPhysicalVolume* CuCover_phys;
	G4VPhysicalVolume* CuCoverCap_phys;
	G4VPhysicalVolume* PbCap_phys;
	G4VPhysicalVolume* CuHolder_phys;
	G4VPhysicalVolume* CuHolderLow_phys;
	G4VPhysicalVolume* CuHolderUp_phys;
	G4VPhysicalVolume* CuCryo_phys;
	G4VPhysicalVolume* CuCryoLow_phys;
	G4VPhysicalVolume* CuCryoUp_phys;
	G4VPhysicalVolume* MoO3Fomos_phys;
	G4VPhysicalVolume* Bkgrd_phys;
	G4VPhysicalVolume* BkgrdUp_phys;
	G4VPhysicalVolume* BkgrdLow_phys;
	G4VPhysicalVolume* CuFin_phys;
	G4VPhysicalVolume* NdOXi_phys;
	G4VPhysicalVolume* CMORK_phys;
	
	
	//G4VPhysicalVolume* DefineVolumes();
	G4Material* SiO2;
	G4Material* Vacuum;
	G4Material* LAB;
	G4Material* Air;
	G4Material* OrgSteclo;
	G4Material* VM2000;
	G4Material* Copper;
	G4Material* Ssteel;
	G4Material* NaI;
	G4Material* PolyBankaMat;
	G4Material* PotDich;
	G4Material* Lead;
    ////---------------
	//G4VisAttributes* worldVisAtt;
	//G4VisAttributes* quartzVisAtt;
	//G4VisAttributes* quartzWALLVisAtt;
	//G4VisAttributes* LABVisAtt;
	
	
   
};
#endif