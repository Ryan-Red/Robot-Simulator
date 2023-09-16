#include "KNN.hpp"



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
std::vector<std::pair<int, float>> sort(std::map<int, float>& M)
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



void bruteForceKNN(std::vector<node> &nodeList, std::vector<std::vector<coordinate>> polygonVertices, int numNeighbours){

    

    
    int listSize = nodeList.size();

    
    // Loop to create the neighbour candidate list
    for(int i = 0; i < listSize - 1; i++){

        int curNumNeighbours = nodeList[i].getNumNeighbours();
        if(curNumNeighbours >= numNeighbours){
            continue;
        }

        std::map<int, float> M; //map used to sort things later

        node targetNode = nodeList[i];
       
        for(int j = i + 1; j < listSize; j++){
            node otherNode = nodeList[j];

            std::vector<coordinate> line = {targetNode.getCoordinate(), otherNode.getCoordinate()};

            // If the connection would result in a collision, dont add the connection to the map and carry on
            if(lineCollisionDetection(polygonVertices,line) == true){
                continue;
            }

            float dist = euclideanDistance(targetNode.getCoordinate(), otherNode.getCoordinate());
            M.insert(std::pair<int, float>(j, dist));
   
        }

        std::vector<std::pair<int, float>> candidates = sort(M);

        int k = 0;
        int candidateListSize = candidates.size();

        while(nodeList[i].getNumNeighbours() <= numNeighbours && (k < candidateListSize)){

            int reciprocal = candidates[k].first;

            //Max number of neighbours for the targetted node
            if(nodeList[reciprocal].getNumNeighbours() >= numNeighbours){
                k++;
                continue;
            }

            nodeList[i].addNeighbour(candidates[k]);

            // Add in the reciprocal connection as the graph is undirected for the nearest neighbours
            // Assume that if B is a nearest neighbour of A, A is a nearest neighbour of B
            nodeList[reciprocal].addNeighbour(i,candidates[k].second);

            k++;

        }

    }
 




}