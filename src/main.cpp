#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <Collision.h>

const float DEG_TO_RADIANS = M_PI/180.f;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Driving Robot Simulation");



    sf::Texture texture;

    if (!texture.loadFromFile("../assets/Kirby.png"))
    {
        std::cout << "Couldnt load texture" << std::endl; // error...
    }

    sf::Sprite robot;
    robot.setTexture(texture);

    robot.setScale(1/4.f,1/4.f);



    // sf::RectangleShape robot(sf::Vector2f(80.f, 50.f));
    // robot.setFillColor(sf::Color::Blue);
    robot.setOrigin(16.f, 16.f);
    robot.setPosition(390, 290); // Starting position


    sf::RectangleShape wall(sf::Vector2f(200.f, 50.f));


    wall.setFillColor(sf::Color::White);
    wall.setPosition(100, 290); // Starting position
    
    
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
            if(robot.getGlobalBounds().intersects(wall.getGlobalBounds())){
                std::cout << "Collided :(" << std::endl;
                robot.move(-xMove, -yMove);
            }

        }

           
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            robot.rotate(-0.1);
            if(robot.getGlobalBounds().intersects(wall.getGlobalBounds())){
                std::cout << "Collided :(" << std::endl;
                robot.rotate(0.1);
            }
            
        }
           

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ 
            angle = robot.getRotation();
            xMove = -0.1 * cos(angle * DEG_TO_RADIANS);
            yMove = -0.1 * sin(angle * DEG_TO_RADIANS);
            robot.move(xMove, yMove);
            if(robot.getGlobalBounds().intersects(wall.getGlobalBounds())){
                std::cout << "Collided :(" << std::endl;
                robot.move(-xMove, -yMove);
            }
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            robot.rotate(0.1);

            if(robot.getGlobalBounds().intersects(wall.getGlobalBounds())){
                std::cout << "Collided :(" << std::endl;
                robot.rotate(-0.1);
            }
        }
        

        

    
        // rect.setFillColor(sf::Color::Red);

        window.clear();
        window.draw(wall);
        window.draw(robot);
        // window.draw(rect);
        window.display();
    }

    return 0;
}
