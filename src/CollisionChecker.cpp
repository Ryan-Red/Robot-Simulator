#include "CollisionChecker.hpp"


/*
    True if point is in collision, false if point is not in collision
*/
// bool pointInCollision(sf::Image obstaclesDrawing, float x, float y ){
//     // std::cout << obstaclesDrawing.getPixel(static_cast<int>(x), static_cast<int>(y)).r << std::endl;
//     // sf::Color blk(255,255,255);
//     if(obstaclesDrawing.getPixel(static_cast<int>(x), static_cast<int>(y)) == sf::Color::Black){
//         return true;
//     }
//     return false;


// }
bool geometricCollisionDection (std::vector<std::vector<coordinate>> polygonVertices, coordinate pointToCheck){

    std::vector<std::vector<float>> testLine = {{0.f, pointToCheck.y}, {pointToCheck.x, pointToCheck.y}};
    int intersectionCount = 0;

    for(auto& polygon: polygonVertices){
        int numVertices = polygon.size();
        for(int i = 0; i < numVertices; i++){
            std::vector<std::vector<float>> objectLine = {{polygon[i].x, polygon[i].y}, {polygon[(i + 1) % numVertices].x, polygon[(i + 1) % numVertices].y}};
            // std::cout << polygon[i].x << " " <<  polygon[i].y << " " << polygon[(i + 1) % numVertices].x << " " << polygon[(i + 1) % numVertices].y   << std::endl;
            intersectionCount += intersectionDetected(testLine, objectLine);
        }
    }
    // std::cout << "Point: " << pointToCheck.x << " " << pointToCheck.y << " Intersection count: " << intersectionCount << std::endl;
    if((intersectionCount % 2) == 0){
        //Even count means that we are not inside of an obstacle
        std::cout << "Safe!" << std::endl;
        return false;
    }
    return true;
}


bool lineCollisionDetection (std::vector<std::vector<coordinate>> polygonVertices, std::vector<coordinate>line){

    std::vector<std::vector<float>> testLine = {{line[0].x, line[0].y},{line[1].x, line[1].y}};
    int intersection = 0;

    for(auto& polygon: polygonVertices){
        int numVertices = polygon.size();
        for(int i = 0; i < numVertices; i++){
            std::vector<std::vector<float>> objectLine = {{polygon[i].x, polygon[i].y}, {polygon[(i + 1) % numVertices].x, polygon[(i + 1) % numVertices].y}};
            // std::cout << polygon[i].x << " " <<  polygon[i].y << " " << polygon[(i + 1) % numVertices].x << " " << polygon[(i + 1) % numVertices].y   << std::endl;
            
            intersection = intersectionDetected(testLine, objectLine);
            if(intersection != 0){
                return true;
            }
        }
    }
    return false;
    
}



bool lineCollisionDetection (std::vector<std::vector<coordinate>> polygonVertices, std::vector<std::vector<float>>line){

    std::vector<std::vector<float>> testLine = line;
    int intersection = 0;

    for(auto& polygon: polygonVertices){
        int numVertices = polygon.size();
        for(int i = 0; i < numVertices; i++){
            std::vector<std::vector<float>> objectLine = {{polygon[i].x, polygon[i].y}, {polygon[(i + 1) % numVertices].x, polygon[(i + 1) % numVertices].y}};
            // std::cout << polygon[i].x << " " <<  polygon[i].y << " " << polygon[(i + 1) % numVertices].x << " " << polygon[(i + 1) % numVertices].y   << std::endl;
            
            intersection = intersectionDetected(testLine, objectLine);
            if(intersection != 0){
                return true;
            }
        }
    }
    return false;
    
}

bool pointInPolygon(std::vector<float> polygon){

    return true;
}

bool intersectionDetected(std::vector<std::vector<float>>line0, std::vector<std::vector<float>>line1){

    // float m0, m1 = 0.f;
    // float b0, b1 = 0.f;

    float epsilon = 0.1;

    std::vector<float> point00 = line0[0];
    std::vector<float> point10 = line0[1];

    std::vector<float> point01 = line1[0];
    std::vector<float> point11 = line1[1];

    float xMin = std::max(std::min(point00[0],point10[0]),std::min(point01[0],point11[0])) - epsilon;
    float yMin = std::max(std::min(point00[1],point10[1]),std::min(point01[1],point11[1])) - epsilon;

    float xMax = std::min(std::max(point00[0],point10[0]),std::max(point01[0],point11[0])) + epsilon;
    float yMax = std::min(std::max(point00[1],point10[1]),std::max(point01[1],point11[1])) + epsilon;

    // std::cout << "xmin and ymin are: " << xMin << " " << yMin << std::endl;
    // std::cout << "xmax and ymax are: " << xMax << " " << yMax << std::endl;

    // ax + by + c = 0
    float a0 = point00[1] - point10[1];
    float b0 = point10[0] - point00[0];
    float c0 = point00[0] * point10[1]  - point10[0] * point00[1];

    float a1 = point01[1] - point11[1];
    float b1 = point11[0] - point01[0];
    float c1 = point01[0] * point11[1]  - point11[0] * point01[1];


    float x_intersection =  (c0*b1 - b0*c1)/(b0*a1 - a0*b1);

    float y_intersection =  (a0*c1 - a1*c0)/(b0*a1 - a0*b1);



    // if((point11[0] - point01[0]) == 0){
    //     m0 = (point10[1] - point00[1])/(point10[0] - point00[0]);

    // }

    
    // m1 = (point11[1] - point01[1])/(point11[0] - point01[0]);

    


    // b0 = (point00[1] * point10[0] - point10[1] * point00[0])/(point10[0] - point00[0]);
    // b1 = (point01[1] * point11[0] - point11[1] * point01[0])/(point11[0] - point01[0]);

    // std::cout << m0 << " " << b0 << std::endl; 
    // std::cout << m1 << " " << b1 << std::endl; 


    // if(m0 == m1){
    //     if(b0 != b1){
    //         return false; //Lines are parallel
    //     }else{
    //         return true; //Lines are coplanar
    //     }

    // }

    // float x_intersection = (b0 - b1)/(m1 - m0);
    // float y_intersection = x_intersection * m0 + b0;

    std::cout << "Intersection is at: (" << x_intersection << ", " << y_intersection << ")" << std::endl;

    if(x_intersection < xMin || x_intersection > xMax){
        std::cout << "out of bounds on X"<< std::endl;
        return false; //Intersects out of bounds therefore 
    }

    // float y_intersection = x_intersection * m0 + b0;

    if(y_intersection < yMin || y_intersection > yMax){
        std::cout << "out of bounds on Y" << std::endl;
        return false; //Out of bounds again
    }

    return true;

}
int unitTests(){

    bool response;

    //Answer: True, (1,1)
    std::vector<std::vector<float>>line0 = {{0.f,0.f}, {2.f,2.f}};
    std::vector<std::vector<float>>line1 = {{0.f,1.f}, {1.f, 1.f}};
    
    response = intersectionDetected(line0, line1);
    // assert(response == true);
    std::cout << intersectionDetected(line0, line1) << std::endl;

    //Answer: True, (3.906,1.438)
    std::vector<std::vector<float>>line2 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line3 = {{0.f, 0.5}, {7.f, 2.18}};

    response = intersectionDetected(line2, line3);
    // assert(response == true);
    std::cout << intersectionDetected(line2, line3) << std::endl;

    //Answer: False, (3.906,1.438)
    std::vector<std::vector<float>>line4 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line5 = {{0.f, 0.5}, {2, 0.98}};

    response = intersectionDetected(line4, line5);
    // assert(response == false);
    std::cout << intersectionDetected(line4, line5) << std::endl;

    //Answer: False, (-65, 29)
    std::vector<std::vector<float>>line6 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line7 = {{-4.f, -1.5}, {-7.f, 0.f}};
    
    response = intersectionDetected(line6, line7);
    // assert(response == false);
    std::cout << intersectionDetected(line6, line7) << std::endl;

    //Answer: False, (-5.40541, -0.797297)
    std::vector<std::vector<float>>line8 = {{0.f, 0.5}, {2, 0.98}};
    std::vector<std::vector<float>>line9 = {{-4.f, -1.5}, {-7.f, 0.f}};

    response = intersectionDetected(line8, line9);
    // assert(response == false);
    std::cout << intersectionDetected(line8, line9) << std::endl;

    return 1;
}

// int main(){

//     return unitTests();


//     // return 1;

// }