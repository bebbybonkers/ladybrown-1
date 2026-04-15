#pragma once
#include "main.h"
#include "objects.hpp"

extern pros::adi::AnalogOut knocker;

extern int knockerState;
extern bool knockerButtonPressed;

void updateKnocker();