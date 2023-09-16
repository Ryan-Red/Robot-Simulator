#pragma once

#include "coordinate.h"
#include <vector>
#include <utility>

class node {

    public:
        node(coordinate coord ):
            coordinate(coord){
                std::vector<std::pair<int, float>> neighbours;
            };


        std::vector<std::pair<int, float>> getNeighbours();

        coordinate getCoordinate();

        void addNeighbour(int n, float cost);
        void addNeighbour(std::pair<int, float> neigh);

        int getNumNeighbours();


    private:
        coordinate coordinate;
        std::vector<std::pair<int, float>> neighbours;

        
};
