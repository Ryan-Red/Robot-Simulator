#include "node.hpp"
#include "coordinate.h"


std::vector<std::pair<int, float>> node::getNeighbours(){

    return neighbours;

}

coordinate node::getCoordinate(){

    return coordinate;

}

void node::addNeighbour(int n, float cost){

    std::pair<int, float> neigh{n, cost};
   

}
void addNeighbour(std::pair<int, float> neigh){
    neighbours.push_back(neigh);

}

int getNumNeighbours(){
    return neighbours.size();
}