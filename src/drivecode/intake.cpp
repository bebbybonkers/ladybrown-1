#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
// intake + outtake

pros::Motor intake(intakePort);
pros::Motor chain(chainPort);
pros::Optical colorSensor(sortPort);
pros::adi::AnalogOut diverter(diverterPort);

int intakeState = 0;
bool intakePressed = false;
bool intakeOn = false;

//intake updates based on state
void updateIntake() {
    if(controller.get_digital(intakeButton)) {
        if(!intakePressed) {
            intakeState+=1;
            intakePressed = true;
            if(intakeState == 0) {
                chain.move_velocity(0);
                intake.move_velocity(0);
                intakeOn = false;
            } else if(intakeState == 1) {
                chain.move_velocity(600);
                intake.move_velocity(600);
                intakeState = -1;
                intakeOn = true;
            }
        } else {
            intakePressed = false;
        }
    }
}

Color checkColor() {
    float hue = colorSensor.get_hue();
    if(hue > redMin && hue < redMax) {
        return RED;
    } else if(hue > blueMin && hue < blueMax) {
        return BLUE;
    } else {
        return NONE;
    }
}


void colorSort() {
    if(intakeOn) {
        Color color = checkColor();
        if(color != yourColor) {
            pros::delay(delayTime);
            diverter.set_value(true);
        } else if(color == BLUE) {
            diverter.set_value(false);
        } else if (color == NONE) {
            diverter.set_value(false);
        }
    }
}
