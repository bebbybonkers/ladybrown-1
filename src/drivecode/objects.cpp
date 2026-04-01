#include "drivecode/objects.hpp"
// controller defintion
pros::Controller controller(pros::E_CONTROLLER_MASTER);
// motor groups and for drivetrain
pros::MotorGroup leftMotors({0,0,0});
pros::MotorGroup rightMotors({0,0,0});
// drivetrain definition
lemlib::Drivetrain drivetrain(
    &leftMotors,
    &rightMotors,
    0,
    lemlib::Omniwheel::NEW_325,
    360,
    0
);

//odometry sensors defined
lemlib::OdomSensors odomSensors(
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
);


// PIDS ready to be tuned
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

// chassis
lemlib::Chassis chassis(
    drivetrain,
    lateralController,
    angularController,
    odomSensors
);
