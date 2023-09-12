// #pragma once

#include "coordinate.h"
#include <vector>
#include <utility>

class node {

    public:
        node(coordinate coord):
            coordinate(coord){};


        std::vector<std::pair<node*, float>> getNeighbours();

        coordinate getCoordinate();

        void addNeighbour(node *node, float cost);


    private:
        coordinate coordinate;
        std::vector<std::pair<node*, float>> neighbours;

        
};
