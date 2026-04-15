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
            intakeOn = !intakeOn;
            intakePressed = true;
            if(!intakeOn) {
                chain.move_velocity(0);
                intake.move_velocity(0);
            } else if(intakeOn) {
                chain.move_velocity(600);
                intake.move_velocity(600);
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

//sort colors, use yourColor (defined in objects.hpp)
void colorSort() {
    if(intakeOn) {
        Color color = checkColor();
        if(color != yourColor) {
            pros::delay(delayTime);
            diverter.set_value(true);
        } else if(color == yourColor) {
            diverter.set_value(false);
        } else if (color == NONE) {
            diverter.set_value(false);
        }
    }
}
