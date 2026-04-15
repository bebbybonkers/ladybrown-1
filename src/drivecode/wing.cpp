// #include "drivecode/wing.hpp"
// #include "drivecode/objects.hpp"
// //descore wing code
// pros::adi::AnalogOut wing(wingPort); 

// int wingState = 0;
// bool wingButtonPressed = false;

// //uses state system
// void updateWing() {
//     if(controller.get_digital(wingButton)) { 
//         if(!wingButtonPressed) {
//             wingState++;
//             wingButtonPressed = true;
//             if(wingState == 0) {
//                 wing.set_value(false);
//             } else if(wingState == 1) {
//                 wing.set_value(true);
//             } else if(wingState == 2) {
//                 wing.set_value(false);
//                 wingState = 0;
//             }
//         }
//     } else {
//         wingButtonPressed = false;
//     }
// }
