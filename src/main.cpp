#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "AStar.hpp"
// #include <Collision.h>

const float DEG_TO_RADIANS = M_PI/180.f;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Driving Robot Simulation");


    sf::RectangleShape wall(sf::Vector2f(200.f, 50.f));


    wall.setFillColor(sf::Color::White);
    wall.setPosition(100, 290); // Starting position


    sf::RectangleShape wall2(sf::Vector2f(100.f, 150.f));


    wall2.setFillColor(sf::Color::White);
    wall2.setPosition(300, 310); // Starting position
    wall2.setRotation(70.0f);
   




    sf::Image image;
    image.create(window.getSize().x, window.getSize().y, sf::Color::Black);
    sf::Texture texture;
    sf::Sprite sprite;

    window.draw(wall2);
    window.draw(wall);
    window.display();

    
    


    coordinate start = {500, 500};

    coordinate goal = {10, 10};

    int numPoints = 5000;

    std::vector<std::vector<coordinate>> polygonVertices = {{{100.f, 290.f}, {300.f, 290.f}, {300.f, 340.f}, {100.f, 340.f}}, {{300, 310}, {400, 350}, {400, 410}, {300, 410}}};

    
    std::vector<node> nodeList = createNodeList (start, goal, polygonVertices, numPoints);


    // std::vector<coordinate> coordinateList = prmGenerator(start,goal, polygonVertices, 5000);
    for (auto& node : nodeList){
        coordinate coord = node.getCoordinate();
        image.setPixel(coord.x, coord.y,{255,0,0});
        // std::cout << node.x << " " << node.y << std::endl;
            
    }

    texture.loadFromImage(image);
    sprite.setTexture(texture);

    window.draw(sprite);


    
   
    // for (auto& nodeCol : nodeList){
    //         for(auto& node: nodeCol){
    //             image.setPixel(node.coordinate.x, node.coordinate.y,{255,0,0});
    //             std::cout << node.coordinate.x << " " << node.coordinate.y << std::endl;
    //         }
    // }

   

    sf::RectangleShape robot(sf::Vector2f(80.f, 50.f));
    robot.setFillColor(sf::Color::Blue);
    robot.setOrigin(40.f, 25.f);
    robot.setPosition(390, 290); // Starting position


    
    
    float angle = 0.f;


    sf::Vector2u windowSize = window.getSize();
    sf::Texture tex;
    tex.create(windowSize.x, windowSize.y);
    tex.update(window);
    sf::Image obstaclesDrawing = tex.copyToImage();
    int ret = obstaclesDrawing.saveToFile("img.png");

    std::cout << "Return is: " << ret << std::endl;

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

        window.draw(sprite);
        // window.draw(wall);

        window.draw(robot);
        // window.draw(rect);
        window.display();
    }

    return 0;
}
