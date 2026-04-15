// #include "drivecode/trapdoor.hpp"
// #include "drivecode/objects.hpp"
// // trapdoor code (switch to midgoal scoring)
// pros::adi::AnalogOut trapdoor(trapdoorPort);

// int trapdoorState = 0;
// bool trapdoorButtonPressed = false;

// // trapdoor uses state system
// void updateTrapdoor() {
//     if(controller.get_digital(trapdoorButton)) { 
//         if(!trapdoorButtonPressed) {
//             trapdoorState++;
//             trapdoorButtonPressed = true;
//             if(trapdoorState == 0) {
//                 trapdoor.set_value(false); 
//             } else if(trapdoorState == 1) {
//                 trapdoor.set_value(true);
//             } else if(trapdoorState == 2) {
//                 trapdoor.set_value(false);
//                 trapdoorState = 0;
//             }
//         }
//     } else {
//         trapdoorButtonPressed = false;
//     }
// }