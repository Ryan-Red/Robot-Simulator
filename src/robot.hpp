#pragma once
#include <vector>
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include "trajectoryRollout.hpp"
#include <Eigen/Dense>
#include <cmath>
#include "coordinate.h"
#include "state.h"
#include "robotInputCommand.h"
#include "shape.h"
#include "distance.hpp"





class Robot{

    public:
        Robot(state state0, shape shape, float maxCurvature, float baseLength, float dt = 0.05):
                m_state(state0),
                m_shape(shape),
                m_maxCurvature(maxCurvature),
                m_baseLength(baseLength),
                m_dt(dt){
                    // m_kinematicsMatrix(2,4);

                };

        // void updateKinematicsMatrix();

        void updateState(robotInputCommand command);

        void setClosenessRadius(float closenessRadius);

        float getDt();

        state getCurrentState();

        bool isNear(coordinate target);

        void setDt(float dt);


        // Robot(std::vector<int> shape, std::vector<int> initialLoc, std::vector<int> color):
        //     m_shape(shape),
        //     m_pose(initialLoc),
        //     m_color(color){};
        


    private:

        Eigen::MatrixXd m_kinematicsMatrix;
        state m_state;
        shape m_shape;
        float m_maxCurvature = 0.52;
        float m_baseLength;
        float m_dt;

        float m_closenessRadius = 25;
        // std::vector<int> m_color;


};