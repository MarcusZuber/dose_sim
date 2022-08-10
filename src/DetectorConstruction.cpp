//
// Created by yz5083 on 08.08.22.
//

#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4Ellipsoid.hh>
#include "DetectorConstruction.h"
#include <G4SystemOfUnits.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>


G4VPhysicalVolume *DetectorConstruction::Construct() {
    auto air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");
    auto worldGeometry = new G4Box("worldGeometry", 5 * mm, 5 * mm, 2 * cm);
    auto worldLogicalVolume = new G4LogicalVolume(worldGeometry, air, "worldLogicalVolume");
    auto worldPlacement = new G4PVPlacement(nullptr,
                                            G4ThreeVector(0, 0, 0),
                                            worldLogicalVolume,
                                            "worldPlacement",
                                            nullptr,
                                            false,
                                            0,
                                            true);


    auto sampleGeometry = new G4Ellipsoid("sampleGeometry", 500 * um, 200 * um, 200 * um);
    auto sampleLogicalVolume = new G4LogicalVolume(sampleGeometry, sampleMaterial, "sampleLogicalVolume");
    [[maybe_unused]] auto samplePlacement = new G4PVPlacement(nullptr,
                                                              G4ThreeVector(0, 0, 1 * cm),
                                                              sampleLogicalVolume,
                                                              "samplePlacement",
                                                              worldLogicalVolume,
                                                              false,
                                                              0,
                                                              true);
    scoringVolume = sampleLogicalVolume;
    return worldPlacement;
}

DetectorConstruction::DetectorConstruction(G4Material* material): sampleMaterial(material) {

}
