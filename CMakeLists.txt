cmake_minimum_required(VERSION 3.23)
project(dose)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

include_directories(include)

add_executable(dose
        main.cpp
        src/DetectorConstruction.cpp
        src/PhysicsList.cpp
        src/ActionInitialization.cpp
        src/PrimaryGenerator.cpp
        src/RunAction.cpp
        src/SteppingAction.cpp
        src/EventAction.cpp)

target_link_libraries(dose ${Geant4_LIBRARIES})

