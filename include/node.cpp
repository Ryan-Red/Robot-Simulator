#include "node.hpp"
#include "coordinate.h"


std::vector<std::pair<node*, float>> node::getNeighbours(){

    return neighbours;

}

coordinate node::getCoordinate(){

    return coordinate;

}

void node::addNeighbour(node *n, float cost){

    std::pair<node*, float> neigh{n, cost};
    neighbours.push_back(neigh);

}