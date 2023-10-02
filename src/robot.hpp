#include <vector>
// #include <SFML/Graphics.hpp>
// #include <iostream>
#include <Eigen/Dense>
#include <cmath>



typedef struct state{

    float x;
    float y;
    float theta;
    float gamma;


} state;

typedef struct shape{

    float width;
    float length;

} shape;


class Robot{

    public:
        Robot(Eigen::MatrixXd kinematicsMatrix, state state0, shape shape, float maxCurvature, float baseLength, float dt = 0.1):
                m_kinematicsMatrix(kinematicsMatrix),
                m_state(state0),
                m_shape(shape),
                m_maxCurvature(maxCurvature),
                m_baseLength(baseLength),
                m_dt(dt){};

        void updateKinematicsMatrix();

        void updateState(float velocity, float turning_rate);
        // Robot(std::vector<int> shape, std::vector<int> initialLoc, std::vector<int> color):
        //     m_shape(shape),
        //     m_pose(initialLoc),
        //     m_color(color){};
        


    private:

        Eigen::MatrixXd m_kinematicsMatrix;
        state m_state;
        shape m_shape;
        float m_maxCurvature;
        float m_baseLength;
        float m_dt;
        // std::vector<int> m_color;


};