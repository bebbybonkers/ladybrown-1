#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
// intake + outtake

pros::Motor intake(0);

int intakeState = 0;
bool button1Pressed = false;

//intake updates based on state
void updateIntake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        if(!button1Pressed) {
            intakeState+=1;
            button1Pressed = true;
            if(intakeState == 0) {
                intake.move_velocity(0);
            } else if(intakeState == 1) {
                intake.move_velocity(600);
                intakeState = -1;
            }
        } else {
            button1Pressed = false;
        }
    }
}

int outtakeState = 0;
bool button2Pressed = false;

// outtake updates based on state
void updateOuttake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        if(!button2Pressed) {
            outtakeState++;
            button2Pressed = true;
            if(outtakeState == 0) {
                intake.move_velocity(0);
            } else if(outtakeState == 1) {
                intake.move_velocity(-600);
                outtakeState = -1;
            }
        } else {
            button2Pressed = false;
        }
    }
}