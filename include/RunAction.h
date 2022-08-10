//
// Created by yz5083 on 08.08.22.
//

#ifndef DOSE_RUNACTION_H
#define DOSE_RUNACTION_H

#include <G4UserRunAction.hh>
#include <G4Accumulable.hh>

class RunAction: public G4UserRunAction{
public:
    RunAction();
    ~RunAction() override = default;
    void EndOfRunAction(const G4Run*) override;
    void BeginOfRunAction(const G4Run*) override;
    void addDepositedEnergy(G4double energy);

private:
    G4Accumulable<G4double> E_dep = 0.0;
};


#endif //DOSE_RUNACTION_H
