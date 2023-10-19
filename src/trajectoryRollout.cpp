#include "trajectoryRollout.hpp"



std::vector<coordinate> rolloutSingleTrajectory(Robot robot, float velocity, float rotation, float timeDuration){


    std::vector<coordinate> trajectory;

    state curState = robot.getCurrentState();
    float dt = robot.getDt();

    trajectory.emplace_back(coordinate{curState.x,curState.y});

    int totalTimesteps = static_cast<int>(timeDuration/dt);
    robotInputCommand command{velocity, rotation};

    for(int i = 0; i < totalTimesteps; i++){
        robot.updateState(command);
        curState = robot.getCurrentState();
        trajectory.emplace_back(coordinate{curState.x,curState.y});
    }

    return trajectory;
    
}


std::vector<std::vector<coordinate>> rolloutManyTrajectories(Robot robot, float velocity, std::vector<float> rotationRange, int numTrajectories, float timeDuration){
    
    state curState = robot.getCurrentState();
    float dt = robot.getDt();

    int totalTimesteps = static_cast<int>(timeDuration/dt);

    std::vector<std::vector<coordinate>> trajectoryList;

    std::vector<coordinate> trajectory;

    float rotationDiff = (rotationRange[1] - rotationRange[0])/(float)(numTrajectories-1);

    for(int j = 0; j < numTrajectories; j++){
        float curRot = rotationRange[0] + j* rotationDiff;
        trajectory = rolloutSingleTrajectory(robot,velocity,curRot,timeDuration);
        trajectoryList.emplace_back(trajectory);
    }

    return trajectoryList;


}

inputCommandTrajectory findBestCommand(Robot robot, coordinate target){

    std::vector<float> rotationRange = {-0.2, 0.2};
    float velocity = 20.f;
    int numTrajectories = 7;
    float timeDuration = 5.0;
    float rotationDiff = (rotationRange[1] - rotationRange[0])/(float)(numTrajectories-1);
    

    std::vector<std::vector<coordinate>> trajectoryList = rolloutManyTrajectories(robot, velocity, rotationRange, numTrajectories, timeDuration);

    std::vector<float> score;
    float minScore = 999999.0f;
    float bestRotation;
    std::vector<coordinate> bestTraj;

    for(int i = 0; i < numTrajectories; i++){
        auto &traj = trajectoryList[i];
        float curScore = euclideanDistance(traj.back(),target);
        if(curScore < minScore){
            minScore = curScore;
            bestRotation = i*rotationDiff + rotationRange[0];
            bestTraj = traj;
            
        }

    }
    robotInputCommand command{velocity,bestRotation};

    inputCommandTrajectory bestCommand{command,bestTraj};

    return bestCommand;

   
    
}

