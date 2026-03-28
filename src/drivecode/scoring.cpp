#include "drivecode/scoring.hpp"
#include "drivecode/objects.hpp"


pros::Motor scoring(0);

int scoringState = 0;
bool button2Pressed = false;

void updateScoring() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        if(!button2Pressed) {
            scoringState+=1;
            button2Pressed = true;
            if(scoringState == 0) {
                scoring.move_velocity(0);
            } else if(scoringState == 1) {
                scoring.move_velocity(600);
            } else if(scoringState == 2) {
                scoring.move_velocity(-600);
                scoringState = -1;
            }
        }
    } else {
        button2Pressed = false;
    }
}