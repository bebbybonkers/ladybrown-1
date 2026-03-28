#pragma once
#include "main.h"
#include "objects.hpp"

extern pros::adi::AnalogOut trapdoor;

extern int trapdoorState;
extern bool trapdoorButtonPressed;

void updateTrapdoor();