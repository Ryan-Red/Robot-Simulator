#pragma once

#include "robot.hpp"
#include <vector>
#include "coordinate.h"
#include "distance.hpp"
#include "robotInputCommand.h"
#include <iostream>

typedef struct inputCommandTrajectory{
    robotInputCommand command;
    std::vector<coordinate> trajectory;

} inputCommandTrajectory;

std::vector<coordinate> rolloutSingleTrajectory(Robot robot, float velocity, float rotation, float timeDuration);


std::vector<std::vector<coordinate>> rolloutManyTrajectories(Robot robot, float velocity, std::vector<float> rotationRange, int numTrajectories, float timeDuration);

inputCommandTrajectory findBestCommand(Robot robot, coordinate target, float velocity = 20.f, float timeDuration = 2.5, int numTrajectories = 7, std::vector<float> rotationRange = {-0.2, 0.2});

std::vector<coordinate> rolloutBestTrajectory(Robot &robot, robotInputCommand command, float timeDuration = 2.5);