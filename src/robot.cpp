#include <robot.hpp>


Robot::Robot(std::vector<int> shape, std::vector<int> initialLoc, std::vector<int> color):
    m_shape(shape),
    m_initialLoc(initialLoc),
    m_color(color){



    for(const auto& t: color){
        if(t > 255){
            std::cerr << "Invalid color entered, defaulting to RGB = 100, 100, 100" << std::endl;
            m_color = std::vector<int>{100, 100, 100};
            break;
        }
    }
            



}