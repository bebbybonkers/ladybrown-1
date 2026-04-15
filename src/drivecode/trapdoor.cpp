#include "drivecode/knocker.hpp"
#include "drivecode/objects.hpp"
// knocker code - knock down mogos
pros::adi::AnalogOut knocker(knockerPort);

int knockerState = 0;
bool knockerButtonPressed = false;

// knocker uses state system
void updateKnocker() {
    if(controller.get_digital(knockerButton)) { 
        if(!knockerButtonPressed) {
            knockerState++;
            knockerButtonPressed = true;
            if(knockerState == 0) {
                knocker.set_value(false); 
            } else if(knockerState == 1) {
                knocker.set_value(true);
            } else if(knockerState == 2) {
                knocker.set_value(false);
                knockerState     = 0;
            }
        }
    } else {
        knockerButtonPressed = false;
    }
}