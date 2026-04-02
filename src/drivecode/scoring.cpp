#include "drivecode/scoring.hpp"
#include "drivecode/objects.hpp"
// scoring - the last motor to score into long goals

pros::Motor scoring(scoringPort);

int scoringState = 0;
bool scoringPressed = false;

//scoring updates based on state
void updateScoring() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        if(!scoringPressed) {
            scoringState+=1;
            scoringPressed = true;
            if(scoringState == 0) {
                scoring.move_velocity(0);
            } else if(scoringState == 1) {
                scoring.move_velocity(600);
                scoringState = -1;
            }
        } else {
            scoringPressed = false;
        }
    }
}
