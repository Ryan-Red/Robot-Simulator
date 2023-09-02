#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
class Robot{

    public:
        void Robot(std::vector<int> shape, std::vector<int> initialLoc, std::vector<int> color):
            m_shape(shape),
            m_pose(initialLoc),
            m_color(color){}
        
        void update




    private:
        std::vector<int> m_pose;
        std::vector<int> m_shape;
        std::vector<int> m_color;






}