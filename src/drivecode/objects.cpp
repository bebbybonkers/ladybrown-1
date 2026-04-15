#include "drivecode/objects.hpp"
#include "pros/misc.h"

//subsystem ports - adjusting these will change the ports that the code uses for each subsystem
int intakePort = 0;
int IMUPort = 0;
int stakePort = 0;
int chainPort = 0;
char diverterPort = 'A';
char sortPort = 'A';
char clampPort = 'A';
// motor groups and for drivetrain
pros::MotorGroup leftMotors({0,0,0});
pros::MotorGroup rightMotors({0,0,0});

// controller defintion
pros::Controller controller(pros::E_CONTROLLER_MASTER);
//controls
pros::controller_digital_e_t intakeButton = pros::E_CONTROLLER_DIGITAL_L1;
pros::controller_digital_e_t clampButton = pros::E_CONTROLLER_DIGITAL_UP;
pros::controller_digital_e_t stakeButton = pros::E_CONTROLLER_DIGITAL_R1;

// optical sensor color values
int redMin = 0;
int redMax = 0;
int blueMin = 0;
int blueMax = 0;
int delayTime = 500; //diverter delay time
Color yourColor = BLUE; //set this to your alliance color for sorting

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
