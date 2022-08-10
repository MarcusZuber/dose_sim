//
// Created by yz5083 on 08.08.22.
//

#include "PhysicsList.h"
#include <G4EmPenelopePhysics.hh>

PhysicsList::PhysicsList() {
    RegisterPhysics( new G4EmPenelopePhysics() );
}
