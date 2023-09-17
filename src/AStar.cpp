#include "AStar.hpp"

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


std::vector<node> createNodeList (coordinate lower, coordinate upper, std::vector<std::vector<coordinate>> polygonVertices, int numPoints){

    float xMin = std::min(lower.x, upper.x);
    float xMax = std::max(lower.x, upper.x);


    float yMin = std::min(lower.y, upper.y);
    float yMax = std::max(lower.y, upper.y);


    std::vector<node> nodeList; 

    std::vector<coordinate> coordinateList = prmGenerator(lower, upper, polygonVertices, numPoints);
    for (auto& coord : coordinateList){
           
        node tempNode(coord);
        nodeList.push_back(tempNode);
            
    }


    return nodeList;

}

std::vector<int> reconstructPath(std::map<int,int> cameFrom, int current){
    std::vector<int> totalPath;
    std::cout << "reconstructing the path!!" << std::endl;
    while(current != -1){
        std::cout << "current " << current << std::endl; 
        totalPath.insert(totalPath.begin(),current);
        current = cameFrom[current];
        
    }
    return totalPath;

}

std::vector<int> AStar(coordinate start, coordinate goal, std::vector<std::vector<coordinate>> polygonVertices, std::vector<node> nodeList, std::function<float(coordinate, coordinate)>h){


    std::cout << "Start is: " << nodeList[nodeList.size() - 2].getCoordinate().x << " " << nodeList[nodeList.size() - 2].getCoordinate().y << std::endl; 
    std::cout << "Goal is: " << nodeList[nodeList.size() - 1].getCoordinate().x << " " << nodeList[nodeList.size() - 1].getCoordinate().y << std::endl; 
   
    int startIdx = nodeList.size() - 2;
    int goalIdx = nodeList.size() - 1;




    std::priority_queue<nodeDistance, std::vector<nodeDistance>, comp> openSet; //Set of discoverd nodes


    openSet.push(nodeDistance(startIdx, 0.f));// size - 2 because we added it to the 2nd last spot

    // cameFrom[n] = last node traversed to make it to n
    std::map<int,int> cameFrom;

    for(int i = 0; i < nodeList.size(); i++ ){
        cameFrom[i] = -1;
    }



    // gScore(n) = least cost to get to n;
    std::map<int,float> gScore;

    for(int i = 0; i < nodeList.size(); i++){
        gScore[i] = 9999999.f;
    }
    gScore[startIdx] = 0; // Starting score is 0 for start node;

    std::map<int,float> fScore; //fScore = h(n) + g(n)

    for(int i = 0; i < nodeList.size(); i++){
        fScore[i] = 9999999.f;
    }

    fScore[startIdx] = h(start,goal); // fScore for start is only the heuristic func

    std::cout << "Starting the A* loop" << std::endl;

    while(openSet.size() != 0){

        nodeDistance current = openSet.top();

        int currentIdx = current.first;

        
        std::cout << "Current index: "<< currentIdx << " current cost: " << fScore[currentIdx] << std::endl;

        node curNode = nodeList[currentIdx];
        if(current.first == goalIdx){
            return reconstructPath(cameFrom, currentIdx);
        }

        openSet.pop();
        float curScore = gScore[currentIdx];

        for(auto neigh: curNode.getNeighbours()){

            int neighbourIdx = neigh.first;
            float neighbourCost = neigh.second;

            float tentative_gScore = curScore + neighbourCost;

            if(tentative_gScore < gScore[neighbourIdx]){
                cameFrom[neighbourIdx] = current.first;
                gScore[neighbourIdx] = tentative_gScore;
                fScore[neighbourIdx] = tentative_gScore +  h(nodeList[neighbourIdx].getCoordinate(),goal);
                openSet.push(nodeDistance(neighbourIdx,fScore[neighbourCost]));
            }

        }
        


    }
    std::cout << "failed :(" << std::endl;

    std::vector<int> failure;  
    return failure;


}