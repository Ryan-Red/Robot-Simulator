#pragma once

#include "robot.hpp"
#include <vector>
#include "coordinate.h"

std::vector<coordinate> rolloutSingleTrajectory(Robot robot, float velocity, float rotation);


