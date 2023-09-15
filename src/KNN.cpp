#include "KNN.hpp"


float euclideanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2) + pow(current.y - goal.y,2));
}

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
 
// Function to sort the map according
// to value in a (key-value) pairs
std::vector<std::pair<node*, float>> sort(std::map<int, float>& M)
{
 
    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    std::set<std::pair<int, float>, comp> S(M.begin(), M.end());
 
    std::vector<std::pair<int, float>> sortedVect;

    // Print the sorted value
    for (auto& it : S) {
        sortedVect.push_back(std::pair<int, float>(it.first, it.second));
        // cout << it.first << ' ' << it.second << endl;
    }
    return sortedVect;
}



void bruteForceKNN(std::vector< std::vector<node>> *nodeList, std::vector<std::vector<coordinate>> polygonVertices, int numNeighbours){

    

     // Declare Map
    
    int listSize = (*nodeList).size();

    

    for(int i = 0; i < listSize - 1; i++){

        int curNumNeighbours = (*nodeList)[i].getNumNeighbours();
        if(curNumNeighbours >= numNeighbours){
            continue;
        }

        std::map<int, float> M;

        node targetNode = (*nodeList)[i];
       
        for(int j = i + 1; j < listSize; j++){
            node otherNode = (*nodeList)[j];

            float dist = euclideanDistance(targetNode.getCoordinate(), otherNode.getCoordinate());
            M.insert(std::pair<int, float>(j, dist));
   
        }
        std::vector<std::pair<int, float>> candidates = sort(M);

        int k = 0;
        while((*nodeList)[i].getNumNeighbours() <= numNeighbours){

            
            int reciprocal = candidates[k].first;

            //Max number of neighbours for the targetted node
            if((*nodeList)[reciprocal].getNumNeighbours() >= numNeighbours){
                k++;
                continue;
            }

            (*nodeList)[i].addNeighbour(candidates[k]);

            // Add in the reciprocal connection as the graph is undirected for the nearest neighbours
            // Assume that if B is a nearest neighbour of A, A is a nearest neighbour of B
            (*nodeList)[reciprocal].addNeighbour(i,candidates[k].second);

            k++;

        }

    }
 
    // Function Call
    sort(M);




}