#pragma once

#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#include <random>
#include "coordinate.h"
#include "node.hpp"
#include "CollisionChecker.hpp"
#include "distance.hpp"


std::vector<node> createNodeList (coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, int numPoints);

std::vector<float> uniformGenerator(float min, float max, int count);

float euclideanDistance(coordinate current, coordinate goal);

float manhattanDistance(coordinate current, coordinate goal);

bool AStar(coordinate start, coordinate goal, std::function<float(coordinate, coordinate)>h);