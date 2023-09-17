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
#include "KNN.hpp"

std::vector<node> createNodeList (coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, int numPoints);

std::vector<float> uniformGenerator(float min, float max, int count);


std::vector<coordinate> prmGenerator(coordinate topLeft, coordinate bottomRight, std::vector<std::vector<coordinate>> polygonVertices, int count);



std::vector<int> AStar(coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, std::vector<node> nodeList, std::function<float(coordinate, coordinate)>h);

std::vector<int> reconstructPath(std::map<int,int> cameFrom, int current);