#include <iostream>
#include <vector>
// #include <algorithm>

bool pointInPolygon(std::vector<float> polygon){



    return true;
}

bool intersectionDetected(std::vector<std::vector<float>>line0, std::vector<std::vector<float>>line1){

    float m0, m1 = 0.f;
    float b0, b1 = 0.f;


    std::vector<float> point00 = line0[0];
    std::vector<float> point10 = line0[1];

    std::vector<float> point01 = line1[0];
    std::vector<float> point11 = line1[1];

    float xMin = std::max(std::min(point00[0],point10[0]),std::min(point01[0],point11[0]));
    float yMin = std::max(std::min(point00[1],point10[1]),std::min(point01[1],point11[1]));

    float xMax = std::min(std::max(point00[0],point10[0]),std::max(point01[0],point11[0]));
    float yMax = std::min(std::max(point00[1],point10[1]),std::max(point01[1],point11[1]));

    m0 = (point10[1] - point00[1])/(point10[0] - point00[0]);
    m1 = (point11[1] - point01[1])/(point11[0] - point01[0]);


    b0 = (point00[1] * point10[0] - point10[1] * point00[0])/(point10[0] - point00[0]);
    b1 = (point01[1] * point11[0] - point11[1] * point01[0])/(point11[0] - point01[0]);

    // std::cout << m0 << " " << b0 << std::endl; 

    if(m0 == m1){
        if(b0 != b1){
            return false; //Lines are parallel
        }else{
            return true; //Lines are coplanar
        }

    }

    float x_intersection = (b0 - b1)/(m1 - m0);
    float y_intersection = x_intersection * m0 + b0;

    std::cout << "Intersection is at: (" << x_intersection << ", " << y_intersection << ")" << std::endl;

    if(x_intersection < xMin || x_intersection > xMax){
        return false; //Intersects out of bounds therefore 
    }

    // float y_intersection = x_intersection * m0 + b0;

    if(y_intersection < yMin || y_intersection > yMax){
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
    assert(response == true);
    std::cout << intersectionDetected(line0, line1) << std::endl;

    //Answer: True, (3.906,1.438)
    std::vector<std::vector<float>>line2 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line3 = {{0.f, 0.5}, {7.f, 2.18}};

    response = intersectionDetected(line2, line3);
    assert(response == true);
    std::cout << intersectionDetected(line2, line3) << std::endl;

    //Answer: False, (3.906,1.438)
    std::vector<std::vector<float>>line4 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line5 = {{0.f, 0.5}, {2, 0.98}};

    response = intersectionDetected(line4, line5);
    assert(response == false);
    std::cout << intersectionDetected(line4, line5) << std::endl;

    //Answer: False, (-65, 29)
    std::vector<std::vector<float>>line6 = {{0.f, 3.f}, {7.5, 0.f}};
    std::vector<std::vector<float>>line7 = {{-4.f, -1.5}, {-7.f, 0.f}};
    
    response = intersectionDetected(line6, line7);
    assert(response == false);
    std::cout << intersectionDetected(line6, line7) << std::endl;

    //Answer: False, (-5.40541, -0.797297)
    std::vector<std::vector<float>>line8 = {{0.f, 0.5}, {2, 0.98}};
    std::vector<std::vector<float>>line9 = {{-4.f, -1.5}, {-7.f, 0.f}};

    response = intersectionDetected(line8, line9);
    assert(response == false);
    std::cout << intersectionDetected(line8, line9) << std::endl;

    return 1;
}

int main(){

    return unitTests();


    // return 1;

}