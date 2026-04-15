#include "drivecode/clamp.hpp"
#include "drivecode/objects.hpp"
//matchloader

pros::adi::AnalogOut clamp(clampPort);

int clampState = 0;
bool clampButtonPressed = false;

//matchloader updates based on state
void updateClamp() {
    if(controller.get_digital(clampButton)) {
        if(!clampButtonPressed) {
            clampState++;
            clampButtonPressed = true;
            if(clampState == 0) {
                clamp.set_value(false);
            } else if(clampState == 1) {
                clamp.set_value(true);
            } else if(clampState == 2) {
                clamp.set_value(false);
                clampState = 0;
            }
        }
    } else {
        clampButtonPressed = false;

    }
}
