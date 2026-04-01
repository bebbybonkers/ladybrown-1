#include "drivecode/loader.hpp"
#include "drivecode/objects.hpp"
//matchloader

pros::adi::AnalogOut loader('A');

int loaderState = 0;
bool loaderButtonPressed = false;

//matchloader updates based on state
void updateLoader() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        if(!loaderButtonPressed) {
            loaderState++;
            loaderButtonPressed = true;
            if(loaderState == 0) {
                loader.set_value(false);
            } else if(loaderState == 1) {
                loader.set_value(true);
            } else if(loaderState == 2) {
                loader.set_value(false);
                loaderState = 0;
            }
        }
    } else {
        loaderButtonPressed = false;

    }
}
