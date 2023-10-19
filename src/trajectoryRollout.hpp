#pragma once

#include "robot.hpp"
#include <vector>
#include "coordinate.h"
#include "distance.hpp"
#include "robotInputCommand.h"

typedef struct inputCommandTrajectory{
    robotInputCommand command;
    std::vector<coordinate> trajectory;

} inputCommandTrajectory;

std::vector<coordinate> rolloutSingleTrajectory(Robot robot, float velocity, float rotation, float timeDuration);


std::vector<std::vector<coordinate>> rolloutManyTrajectories(Robot robot, float velocity, std::vector<float> rotationRange, int numTrajectories, float timeDuration);

inputCommandTrajectory findBestCommand(Robot robot, coordinate target);