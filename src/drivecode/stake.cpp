#include "drivecode/stake.hpp"
#include "drivecode/objects.hpp"
// wallstake - motor powers a lift to put rings on wall stake

pros::Motor stake(stakePort);

int stakeState = 0;
bool stakePressed = false;

//stake updates based on state
void updateStake() {
    if(controller.get_digital(stakeButton)) {
        if(!stakePressed) {
            stakeState+=1;
            stakePressed = true;
            if(stakeState == 0) {
                stake.move_velocity(0);
            } else if(stakeState == 1) {
                stake.move_velocity(600);
            } else if(stakeState == 2) {
                stake.move_velocity(-600);
                stakeState = -1;
            }
        } else {
            stakePressed = false;
        }
    }
}
