#include "drivecode/tasks.hpp"

void runTasks() {
    pros::Task intakeTask(updateIntake, "intake task");
    pros::Task mogoClampTask(updateClamp, "mogo clamp task");
    pros::Task KnockerTask(updateKnocker, "knocker task");
    pros::Task checkColorTask(checkColor, "color check task");
}