#pragma once

#include <iostream>
#include <vector>
#include "coordinate.h"

bool intersectionDetected(std::vector<std::vector<float>>line0, std::vector<std::vector<float>>line1);


bool lineCollisionDetection (std::vector<std::vector<coordinate>> polygonVertices, std::vector<std::vector<float>>line);

bool lineCollisionDetection (std::vector<std::vector<coordinate>> polygonVertices, std::vector<coordinate>line);



bool geometricCollisionDection (std::vector<std::vector<coordinate>> polygonVertices, coordinate pointToCheck);

bool intersectionDetected(std::vector<std::vector<float>>line0, std::vector<std::vector<float>>line1);


int unitTests();
