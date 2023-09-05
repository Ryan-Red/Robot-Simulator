#include "AStar.hpp"

struct CompareCost {
    bool operator()(node const& n1, node const& n2)
    {
        // return "true" if "n1" is ordered
        // before "n2", for example:
        return n1.cost < n2.cost;
    }
};

std::vector<float> uniformGenerator(float min, float max, int count)
{    
    float spacing = (max - min)/static_cast<float>(count - 1);

    std::vector <float> output;

    for (int i = 0; i <= count; i++){

        output.emplace_back(min + i * spacing);
    }
    return output;
}

std::vector <int> findStart(coordinate start, std::vector< std::vector<node>>& nodeList){

    int xMax, yMax, xMin, yMin = 0;

    int size  = nodeList.size();
    node maxNode = nodeList[size - 1][size -1];

    if (maxNode.coordinate.x == start.x){
        if(maxNode.coordinate.y == start.y){
            return {0,0};
        }else{
            return {0, size - 1};
        }
    }else{
        if(maxNode.coordinate.y == start.y){
            return {size - 1,0};
        }else{
            return {size - 1, size - 1};
        }
    }

}


std::vector< std::vector<node>> createNodeList (coordinate start, coordinate goal, int numPointsX, int numPointsY){

    float xMin = std::min(start.x, goal.x);
    float xMax = std::max(start.x, goal.x);


    float yMin = std::min(start.y, goal.y);
    float yMax = std::max(start.y, goal.y);



    std::vector<float> xCoords = uniformGenerator(xMin, xMax, numPointsX);
    std::vector<float> yCoords = uniformGenerator(yMin, yMax, numPointsY);

    std::vector< std::vector<node>> nodeList; 


    for (int i = 0; i < numPointsX; i++){
        
        std::vector<node> tempNodeList;
        std::cout << xCoords[i] << std::endl; 
        
        for (int j = 0; j < numPointsY; j++){
            coordinate coord = {xCoords[i], yCoords[j]};
            node tempNode = {0, coord, i, j};
            tempNodeList.push_back(tempNode);
        }
        
        nodeList.push_back(tempNodeList);
       
    }

    return nodeList;

}

float euclideanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2) + pow(current.y - goal.y,2));
}

float manhattanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2)) + sqrt(pow(current.y - goal.y,2));
}

bool AStar(coordinate start, coordinate goal, std::function<float(coordinate, coordinate)>h){

    int numPointsX = 50;
    int numPointsY = 50;

    int totalPoints = numPointsX * numPointsY;

    std::vector< std::vector<node>> nodeList = createNodeList(start, goal, numPointsX, numPointsY);

    std::priority_queue<node, std::vector<node>, CompareCost> openSet; //Set of discoverd nodes

    std::vector<int> startNodeLoc = findStart(start,nodeList);
    node startNode = nodeList[startNodeLoc[0]][startNodeLoc[1]];

    openSet.push(startNode);


    node* cameFrom = nullptr; //Backtracking map

    cameFrom = (node *) malloc(sizeof(node)*totalPoints);








    free(cameFrom);



    return 1;


}