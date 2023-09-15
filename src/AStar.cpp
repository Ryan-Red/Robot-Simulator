#pragma once

#include "AStar.hpp"

// struct CompareCost {
//     bool operator()(node const& n1, node const& n2)
//     {
//         // return "true" if "n1" is ordered
//         // before "n2", for example:
//         return n1.cost < n2.cost;
//     }
// };

std::vector<float> uniformGenerator(float min, float max, int count)
{    
    float spacing = (max - min)/static_cast<float>(count - 1);

    std::vector <float> output;

    for (int i = 0; i <= count; i++){

        output.emplace_back(min + i * spacing);
    }
    return output;
}

std::vector<coordinate> prmGenerator(coordinate topLeft, coordinate bottomRight, std::vector<std::vector<coordinate>> polygonVertices, int count){

    std::vector<coordinate> output;

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_real_distribution<float> distrX(topLeft.x, bottomRight.x);
    std::uniform_real_distribution<float> distrY(topLeft.y, bottomRight.y);

    for(int i = 0; i < count; i++){
        while(true){
            coordinate tmp = {distrX(generator), distrY(generator)};
            bool collided = geometricCollisionDection(polygonVertices, tmp);

            if(collided == false){
                // std::cout << "Safe again!" << std::endl;
                output.emplace_back(tmp);
                break;
            }else{
                std::cout << "collided for point: " << tmp.x << " " << tmp.y << std::endl; 
            }
        }
        
       
    }

    return output;
   
}


// std::vector<coordinate> prmGenerator(coordinate topLeft, coordinate bottomRight, sf::Image obstaclesDrawing, int count){

//     std::vector<coordinate> output;

//     std::random_device                  rand_dev;
//     std::mt19937                        generator(rand_dev());
//     std::uniform_real_distribution<float> distrX(topLeft.x, bottomRight.x);
//     std::uniform_real_distribution<float> distrY(topLeft.y, bottomRight.y);

//     for(int i = 0; i < count; i++){
//         while(true){
//             coordinate tmp = {distrX(generator), distrY(generator)};
//             if(!pointInCollision(obstaclesDrawing,tmp.x, tmp.y)){
//                 output.emplace_back(tmp);
//                 break;
//             }else{
//                 std::cout << "collided for point: " << tmp.x << " " << tmp.y << std::endl; 
//             }
//         }
        
       
//     }

//     return output;
   
// }



std::vector <int> findStart(coordinate start, std::vector< std::vector<node>>& nodeList){

    int xMax, yMax, xMin, yMin = 0;

    int size  = nodeList.size();
    node maxNode = nodeList[size - 1][size -1];

    coordinate maxNodeCoord = maxNode.getCoordinate();

    if (maxNodeCoord.x == start.x){
        if(maxNodeCoord.y == start.y){
            return {0,0};
        }else{
            return {0, size - 1};
        }
    }else{
        if(maxNodeCoord.y == start.y){
            return {size - 1,0};
        }else{
            return {size - 1, size - 1};
        }
    }

}


std::vector<node> createNodeList (coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, int numPoints){

    float xMin = std::min(start.x, goal.x);
    float xMax = std::max(start.x, goal.x);


    float yMin = std::min(start.y, goal.y);
    float yMax = std::max(start.y, goal.y);


    std::vector<node> nodeList; 

    std::vector<coordinate> coordinateList = prmGenerator(start,goal, polygonVertices, numPoints);
    for (auto& coord : coordinateList){
           
        node tempNode(coord);
        nodeList.push_back(tempNode);
            
    }


    return nodeList;

}

float euclideanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2) + pow(current.y - goal.y,2));
}

float manhattanDistance(coordinate current, coordinate goal){
    return sqrt(pow(current.x - goal.x,2)) + sqrt(pow(current.y - goal.y,2));
}

bool AStar(coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, int numPoints, std::function<float(coordinate, coordinate)>h){



    std::vector<node> nodeList = createNodeList(start, goal, polygonVertices, numPoints);

    // std::priority_queue<node, std::vector<node>, CompareCost> openSet; //Set of discoverd nodes

    // std::vector<int> startNodeLoc = findStart(start,nodeList);
    // node startNode = nodeList[startNodeLoc[0]][startNodeLoc[1]];

    // openSet.push(startNode);


    // node* cameFrom = nullptr; //Backtracking map

    // cameFrom = (node *) malloc(sizeof(node)*totalPoints);


    // free(cameFrom);



    return 1;


}