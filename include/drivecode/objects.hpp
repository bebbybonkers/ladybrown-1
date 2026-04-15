#include "main.h"
#include "lemlib/api.hpp"
#include <string>
#pragma once


extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

extern pros::Controller controller;

extern pros::adi::AnalogOut piston;

// ports
extern int intakePort;
extern int stakePort;
extern int IMUPort;
extern int chainPort;
extern char sortPort;
extern char diverterPort;
extern char clampPort;

// controls
extern pros::controller_digital_e_t intakeButton;
extern pros::controller_digital_e_t outtakeButton;
extern pros::controller_digital_e_t trapdoorButton;
extern pros::controller_digital_e_t wingButton;
extern pros::controller_digital_e_t clampButton;
extern pros::controller_digital_e_t stakeButton;

// color sensor values
extern int redMin;
extern int redMax;
extern int blueMin;
extern int blueMax;
extern int delayTime;

enum Color {
    RED,
    BLUE,
    NONE
};
extern Color yourColor;