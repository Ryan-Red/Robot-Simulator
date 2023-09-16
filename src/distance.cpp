#include "distance.hpp"

float euclideanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2) + pow(current.y - goal.y,2));
}

float manhattanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2)) + sqrt(pow(current.y - goal.y,2));
}