#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
// intake + outtake

pros::Motor intake(intakePort);

int intakeState = 0;
bool intakePressed = false;

//intake updates based on state
void updateIntake() {
    if(controller.get_digital(intakeButton)) {
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


bool outtakePressed = false;

// outtake updates based on state
void updateOuttake() {
    if(controller.get_digital(outtakeButton)) {
        if(!outtakePressed) {
            intakeState++;
            outtakePressed = true;
            if(intakeState == 0) {
                intake.move_velocity(0);
            } else if(intakeState == 1) {
                intake.move_velocity(-600);
                intakeState = -1;
            }
        } else {
            outtakePressed = false;
        }
    }
}