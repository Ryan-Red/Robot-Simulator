#include "node.hpp"


std::vector<std::pair<int, float>> node::getNeighbours(){

    return neighbours;

}

coordinate node::getCoordinate(){

    return coordinate;

}

void node::addNeighbour(int n, float cost){

    std::pair<int, float> neigh{n, cost};
    neighbours.push_back(neigh);
   

}
void node::addNeighbour(std::pair<int, float> neigh){
    neighbours.push_back(neigh);

}

int node::getNumNeighbours(){
    return neighbours.size();
}