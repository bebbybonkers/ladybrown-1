#include "main.h"
#include "objects.hpp"
#include "pros/optical.hpp"
#pragma once



extern pros::Motor intake;
extern pros::Motor chain;
extern pros::Optical colorSensor;
extern pros::adi::AnalogOut diverter;
extern pros::Distance distance;

void updateIntake();


extern int intakeState;

extern bool intakePressed;
extern bool intakeOn;


void colorSort();
Color checkColor();
