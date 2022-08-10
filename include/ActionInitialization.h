//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_ACTIONINITIALIZATION_H
#define DOSE_ACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>
#include <G4Types.hh>

class ActionInitialization: public G4VUserActionInitialization{
public:
    ActionInitialization(G4double beam_width, G4double beam_height, G4double energy);
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;
private:
    G4double beam_width;
    G4double beam_height;
    G4double energy;
};


#endif //DOSE_ACTIONINITIALIZATION_H
