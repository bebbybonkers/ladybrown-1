#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
// intake + outtake

pros::Motor intake(intakePort);

int intakeState = 0;
bool intakePressed = false;

//intake updates based on state
void updateIntake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        if(!intakePressed) {
            intakeState+=1;
            intakePressed = true;
            if(intakeState == 0) {
                intake.move_velocity(0);
            } else if(intakeState == 1) {
                intake.move_velocity(600);
                intakeState = -1;
            }
        } else {
            intakePressed = false;
        }
    }
}

int outtakeState = 0;
bool outtakePressed = false;

// outtake updates based on state
void updateOuttake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        if(!outtakePressed) {
            outtakeState++;
            outtakePressed = true;
            if(outtakeState == 0) {
                intake.move_velocity(0);
            } else if(outtakeState == 1) {
                intake.move_velocity(-600);
                outtakeState = -1;
            }
        } else {
            outtakePressed = false;
        }
    }
}