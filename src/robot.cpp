#include "robot.hpp"
#include <iostream>

state Robot::getCurrentState(){

    return m_state;

}

float Robot::getDt(){
    return m_dt;
}

void Robot::setDt(float dt){
    m_dt = dt;
}

bool Robot::isNear(coordinate target){

    coordinate curPos{m_state.x, m_state.y};

    float dist = euclideanDistance(curPos,target);
    std::cout << "dist is: " << dist << std::endl;
    if (dist <= m_closenessRadius){
        return true;
    }
    return false;


}


void Robot::updateState(robotInputCommand command){

    float velocity = command.velocity;
    float turningRate = command.turningRate;

    float theta = m_state.theta;
    float gamma = m_state.gamma;

    m_kinematicsMatrix.resize(4,2);
    // std::cout << "Resized" << std::endl;

    m_kinematicsMatrix << cos(theta),              0,
                          sin(theta),              0,
                          tan(gamma)/m_baseLength, 0,
                          0,                       1;

    Eigen::Vector2d input;

    input << velocity,
             turningRate;

    // std::cout << "About to multiply" << std::endl;

    Eigen::Vector4d q_dot = m_kinematicsMatrix * input; 

    m_state.x = m_state.x + q_dot[0] * m_dt;
    m_state.y = m_state.y + q_dot[1] * m_dt;
    m_state.theta = m_state.theta + q_dot[2] * m_dt;
    m_state.gamma = m_state.gamma + q_dot[3] * m_dt;

    if(m_state.theta > m_maxCurvature){
        m_state.theta = m_maxCurvature;
        m_state.gamma = gamma;
    }





}


 void Robot::setClosenessRadius(float closenessRadius){
    m_closenessRadius = closenessRadius;
 }

