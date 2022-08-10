//
// Created by yz5083 on 08.08.22.
//

#include "PrimaryGenerator.h"
#include <G4ParticleTable.hh>
#include <G4UniformRandPool.hh>
#include <G4SystemOfUnits.hh>


void PrimaryGenerator::GeneratePrimaries(G4Event *event) {
    auto particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");

    auto x = beam_width * (G4UniformRand() - 0.5);
    auto y = beam_height * (G4UniformRand() - 0.5);

    particleGun->SetParticlePosition(G4ThreeVector(x, y, -1 * cm));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
    particleGun->SetParticleEnergy(energy);
    particleGun->SetParticleDefinition(particle);
    particleGun->GeneratePrimaryVertex(event);
}

PrimaryGenerator::PrimaryGenerator(G4double beam_width, G4double beam_height, G4double energy):
beam_width(beam_width), beam_height(beam_height), energy(energy) {
    particleGun = new G4ParticleGun(1);
}

PrimaryGenerator::~PrimaryGenerator() {
    delete particleGun;
}
