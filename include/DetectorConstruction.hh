//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 66586 2012-12-21 10:48:39Z ihrivnac $
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class DetectorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
   ~DetectorConstruction();

  public:

    virtual G4VPhysicalVolume* Construct();

    G4Material* 
    MaterialWithSingleIsotope(G4String, G4String, G4double, G4int, G4int);

    void SetTargetLength(G4double);
    void SetTargetRadius(G4double);
    void SetTargetMaterial(G4String);

  public:

   G4double GetTargetLength()       {return fTargetLength;};
   G4double GetTargetRadius()       {return fTargetRadius;};
   G4Material* GetTargetMaterial()  {return fTargetMaterial;};

   G4double GetWorldSizeX()   {return fWorldSizeX;};
   G4double GetWorldSizeYZ()  {return fWorldSizeYZ;};

   void PrintParameters();

  private:

  G4Material* fTargetMaterial;
  G4Material* fBeamCapMaterial;
  G4Material* fTargetChamberMaterial;
  G4Material* fCoolingHeMaterial;
  G4Material* fTargetSealMaterial;
  G4LogicalVolume* fLTarget;

  G4double fInnerRadius;          // tubs inner radius
  G4double fTargetRadius;         // radius of the water target
  G4double fOuterRadius;          // outer radius of the target chamber
  G4double fTargetLength;         // half length in Z of the water target (could be calculated here)
  G4double fChamberLength;        // half length in Z of the target chamber 0.5 mm chamber back thickness
  G4double fNickelfoilLength;     // half length in Z of the nickel foil
  G4double fSteelfoilLength;      // half length in z of the steel foil
  G4double fHeliumLength;         // half of the cooling helium

   G4double           fWorldSizeX;
   G4double           fWorldSizeYZ;
   G4Material*        fWorldMaterial;
   G4VPhysicalVolume* fWorldVolume;                        

   DetectorMessenger* fDetectorMessenger;

  private:

   void               DefineMaterials();
   G4VPhysicalVolume* ConstructVolumes();     
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
