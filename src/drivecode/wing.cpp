#include "drivecode/wing.hpp"
#include "drivecode/objects.hpp"

pros::adi::AnalogOut wing('A'); 

int wingState = 0;
bool wingButtonPressed = false;

void updateWing() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { 
        if(!wingButtonPressed) {
            wingState++;
            wingButtonPressed = true;
            if(wingState == 0) {
                wing.set_value(false);
            } else if(wingState == 1) {
                wing.set_value(true);
            } else if(wingState == 2) {
                wing.set_value(false);
                wingState = 0;
            }
        }
    } else {
        wingButtonPressed = false;
    }
}
