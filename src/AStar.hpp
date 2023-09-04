#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <random>
#include <iostream>
#include <algorithm>

typedef struct coordinate {
    float x;
    float y;
};


typedef struct node {
    float cost;
    coordinate coordinate;
}; 


float euclideanDistance(coordinate current, coordinate goal);

float manhattanDistance(coordinate current, coordinate goal);

bool AStar(coordinate start, coordinate goal, std::function<float(coordinate, coordinate)>h);