//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_PRIMARYGENERATOR_H
#define DOSE_PRIMARYGENERATOR_H


#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>


class PrimaryGenerator: public G4VUserPrimaryGeneratorAction{
public:
    PrimaryGenerator(G4double beam_width, G4double beam_height, G4double energy);
    ~PrimaryGenerator() override;

    void GeneratePrimaries(G4Event * event) override;
    G4double getBeamArea() const { return beam_height * beam_width;}
private:
    G4ParticleGun * particleGun;
    G4double beam_width;
    G4double beam_height;
    G4double energy;
};


#endif //DOSE_PRIMARYGENERATOR_H
