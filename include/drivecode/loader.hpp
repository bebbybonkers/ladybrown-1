#pragma once
#include "main.h"
#include "objects.hpp"

extern pros::adi::AnalogOut loader;

extern int loaderState;
extern bool loaderButtonPressed;

void updateLoader();