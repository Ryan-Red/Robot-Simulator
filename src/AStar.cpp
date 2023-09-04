#include "AStar.hpp"

std::vector<float> uniformGenerator(float min, float max, int count)
{    
    float spacing = (max - min)/static_cast<float>(count);

    std::vector <float> output;

    for (int i = 0; i < count; i++){

        output.emplace_back(min + i * spacing);
    }
    return output;
}



std::vector< std::vector<node>> createNodeList (coordinate start, coordinate goal, int numPoints){

    float xMin = std::min(start.x, goal.x);
    float xMax = std::max(start.x, goal.x);


    float yMin = std::min(start.y, goal.y);
    float yMax = std::max(start.y, goal.y);

    int sqrtPoints = static_cast<int>(sqrt(numPoints));


    std::vector<float> xCoords = uniformGenerator(xMin, xMax, sqrtPoints);
    std::vector<float> yCoords = uniformGenerator(yMin, yMax, sqrtPoints);

    std::vector< std::vector<node>> nodeList; 


    for (int i = 0; i < sqrtPoints; i++){
        
        std::vector<node> tempNodeList;
        std::cout << xCoords[i] << std::endl; 
        
        for (int j = 0; j < sqrtPoints; j++){
            coordinate coord = {xCoords[i], yCoords[j]};
            node tempNode = {0, coord};
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

    std::priority_queue<node, std::vector<node>, std::greater<node>> openSet;

    node startNode = {0,start};
    // openSet.push(startNode);

    std::vector<node> cameFrom;
    return 1;


}