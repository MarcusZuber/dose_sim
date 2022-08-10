//
// Created by yz5083 on 08.08.22.
//

#include "ActionInitialization.h"
#include "PrimaryGenerator.h"
#include "RunAction.h"
#include "EventAction.h"
#include "SteppingAction.h"
#include <G4SystemOfUnits.hh>

void ActionInitialization::Build() const {
    auto generator = new PrimaryGenerator(beam_width, beam_height, energy);
    SetUserAction(generator);

    auto runAction = new RunAction();
    SetUserAction(runAction);

    auto eventAction = new EventAction(runAction);
    SetUserAction(eventAction);

    SetUserAction(new SteppingAction(eventAction));
}

void ActionInitialization::BuildForMaster() const {
    auto runAction = new RunAction();
    SetUserAction(runAction);

}

ActionInitialization::ActionInitialization(G4double beam_width, G4double beam_height, G4double energy):
beam_width(beam_width), beam_height(beam_height), energy(energy)
{

}
