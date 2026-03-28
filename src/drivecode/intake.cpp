#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"


pros::Motor intake(0);

int intakeState = 0;
bool button1Pressed = false;

void updateIntake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        if(!button1Pressed) {
            intakeState+=1;
            button1Pressed = true;
            if(intakeState == 0) {
                intake.move_velocity(0);
            } else if(intakeState == 1) {
                intake.move_velocity(600);
            } else if(intakeState == 2) {
                intake.move_velocity(-600);
                intakeState = -1;
            }
        }
    } else {
        button1Pressed = false;
    }
}