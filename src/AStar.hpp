#pragma once

#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#include <random>
#include "CollisionChecker.cpp"

typedef struct coordinate {
    float x;
    float y;
} coordinate;


typedef struct node {
    float cost;
    coordinate coordinate;
    int i;
    int j;
} node; 


std::vector< std::vector<node>> createNodeList (coordinate start, coordinate goal, int numPoints);

std::vector<float> uniformGenerator(float min, float max, int count);

float euclideanDistance(coordinate current, coordinate goal);

float manhattanDistance(coordinate current, coordinate goal);

bool AStar(coordinate start, coordinate goal, std::function<float(coordinate, coordinate)>h);