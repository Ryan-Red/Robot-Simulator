#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "AStar.cpp"
// #include <Collision.h>

const float DEG_TO_RADIANS = M_PI/180.f;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Driving Robot Simulation");


    sf::RectangleShape wall(sf::Vector2f(200.f, 50.f));


    wall.setFillColor(sf::Color::White);
    wall.setPosition(100, 290); // Starting position
   
    window.draw(wall);
    window.display();



    sf::Vector2u windowSize = window.getSize();
    sf::Texture tex;
    tex.create(windowSize.x, windowSize.y);
    tex.update(window);
    sf::Image obstaclesDrawing = tex.copyToImage();
    obstaclesDrawing.saveToFile("img.jpg");

    sf::Image image;
    image.create(window.getSize().x, window.getSize().y, sf::Color::Black);
    sf::Texture texture;
    sf::Sprite sprite;

    
    


    coordinate start = {300, 300};

    coordinate goal = {200, 200};

    std::cout << obstaclesDrawing.getPixel(101,290).r << obstaclesDrawing.getPixel(101,290).g << obstaclesDrawing.getPixel(101,290).b << std::endl;

    // std::vector< std::vector<node>> nodeList = createNodeList(start, goal, 20,20);
    std::vector<coordinate> coordinateList = prmGenerator(start,goal, obstaclesDrawing, 10);
    for (auto& node : coordinateList){
           
        image.setPixel(node.x, node.y,{255,0,0});
        std::cout << node.x << " " << node.y << std::endl;
            
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

        window.draw(wall);
        window.draw(robot);
        // window.draw(rect);
        window.display();
    }

    return 0;
}
