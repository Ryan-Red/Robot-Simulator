#pragma once

#include "CollisionChecker.hpp"
#include "node.hpp"
#include <cmath>
#include <map>
#include <set>
#include "distance.hpp"

struct comp {
    template <typename T>
 
    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

typedef std::pair<int,float> nodeDistance;


void bruteForceKNN(std::vector<node> &nodeList, std::vector<std::vector<coordinate>> polygonVertices, int numNeighbours);