#pragma once

#include "CollisionChecker.hpp"
#include "node.hpp"
#include <cmath>
#include <map>
#include <set>
#include "distance.hpp"

void bruteForceKNN(std::vector<node> &nodeList, std::vector<std::vector<coordinate>> polygonVertices, int numNeighbours);