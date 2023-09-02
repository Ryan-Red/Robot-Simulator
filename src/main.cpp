#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


const float DEG_TO_RADIANS = M_PI/180.f;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Driving Robot Simulation");
    sf::RectangleShape robot(sf::Vector2f(80.f, 50.f));
    robot.setFillColor(sf::Color::Blue);
    robot.setOrigin(robot.getSize().x * 0.5f, robot.getSize().y * 0.5f);
    robot.setPosition(390, 290); // Starting position
    
    float angle = 0.f;


    while (window.isOpen()) {

        float xMove = 0.f;
        float yMove = 0.f;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle user input
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            angle = robot.getRotation();
            xMove = 0.1 * cos(angle * DEG_TO_RADIANS);
            yMove = 0.1 * sin(angle * DEG_TO_RADIANS);

            robot.move(xMove, yMove);

        }

           
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            robot.rotate(-0.1);
        }
           

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ 
            angle = robot.getRotation();
            xMove = -0.1 * cos(angle * DEG_TO_RADIANS);
            yMove = -0.1 * sin(angle * DEG_TO_RADIANS);
            robot.move(xMove, yMove);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            robot.rotate(0.1);
        }
        

        window.clear();
        window.draw(robot);
        window.display();
    }

    return 0;
}
