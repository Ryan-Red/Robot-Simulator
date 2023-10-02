#include "robot.hpp"


void Robot::updateState(float velocity, float turning_rate){

    float theta = m_state.theta;
    float gamma = m_state.gamma;

    m_kinematicsMatrix << cos(theta),              0,
                          sin(theta),              0,
                          tan(gamma)/m_baseLength, 0,
                          0,                       1;

    Eigen::Vector2d input;

    input << velocity,
             turning_rate;

    Eigen::Vector4d q_dot = m_kinematicsMatrix * input; 

    m_state.x = m_state.x + q_dot[0] * m_dt;
    m_state.y = m_state.y + q_dot[1] * m_dt;
    m_state.theta = m_state.theta + q_dot[2] * m_dt;
    m_state.gamma = m_state.gamma + q_dot[3] * m_dt;





}