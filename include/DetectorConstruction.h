//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_DETECTORCONSTRUCTION_H
#define DOSE_DETECTORCONSTRUCTION_H

#include <G4VUserDetectorConstruction.hh>

class DetectorConstruction: public G4VUserDetectorConstruction {
public:
    DetectorConstruction(G4Material* material);
    ~DetectorConstruction() override = default;

    /**
     * Constructs the world volume and and sample volume.
     * @return worldPlacement
     */
    G4VPhysicalVolume* Construct() override;

    [[nodiscard]] G4LogicalVolume* GetScoringVolume() const { return scoringVolume; }

protected:
    G4LogicalVolume* scoringVolume = nullptr;
    G4Material* sampleMaterial = nullptr;
};


#endif //DOSE_DETECTORCONSTRUCTION_H
