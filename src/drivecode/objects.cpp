#include "drivecode/objects.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotors({0,0,0});
pros::MotorGroup rightMotors({0,0,0});

lemlib::Drivetrain drivetrain(
    &leftMotors,
    &rightMotors,
    0,
    lemlib::Omniwheel::NEW_325,
    360,
    0
);

lemlib::OdomSensors odomSensors(
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
);

lemlib::ControllerSettings lateralController(
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
);

lemlib::ControllerSettings angularController(
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
);

lemlib::Chassis chassis(
    drivetrain,
    lateralController,
    angularController,
    odomSensors
);
