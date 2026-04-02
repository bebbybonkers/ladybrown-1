#include "drivecode/objects.hpp"


//subsystem ports - adjusting these will change the ports that the code uses for each subsystem
int intakePort = 0;
int scoringPort = 0;
int IMUPort = 0;
char trapdoorPort = 'A';
char wingPort = 'A';
char loaderPort = 'A';
// motor groups and for drivetrain
pros::MotorGroup leftMotors({0,0,0});
pros::MotorGroup rightMotors({0,0,0});

// controller defintion
pros::Controller controller(pros::E_CONTROLLER_MASTER);
// drivetrain definition
lemlib::Drivetrain drivetrain(
    &leftMotors,
    &rightMotors,
    0,
    lemlib::Omniwheel::NEW_325,
    360,
    0
);

pros::IMU imu(IMUPort);
//odometry sensors defined
lemlib::OdomSensors odomSensors(
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu
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
