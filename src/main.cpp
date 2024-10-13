#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <chrono>
#include <thread>
#include "../include/point.hpp"
#include "../include/route.hpp"
#include "../include/consts.hpp"
#include "../include/algo/algo.hpp"
#include "../include/algo/permutation.hpp"
#include "../include/algo/donothing.hpp"
#include "../include/algo/shortest.hpp"




int main(int argc, char* argv[]){


    std::cout << "Traveling salesman\n";

    consts::loadFont();

    uint numberOfPoints = 0;

    try {
        numberOfPoints = std::stoi(argv[1]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    Point* points = Point::createPoints(numberOfPoints);
   

    std::list<Route> routes;

    
    Permutation perm(points);
    DoNothing doNothing(points);
    Shortest shortest(points);

    routes.emplace_back(Route(&perm, sf::Color::Green,1));
    routes.emplace_back(Route(&shortest, sf::Color::Yellow,2));
  
    sf::RenderWindow window(sf::VideoMode(consts::MAX_X, consts::MAX_Y), "Traveling Salesman");

    while (window.isOpen()) {
        sf::Event event;
        window.clear();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        for (auto& route : routes) {
            route.draw(window);
        }
       
        for (uint i = 0; i < numberOfPoints; i++){
            points[i].draw(window);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        window.display();
    }

    delete [] points;

    //algos.clear();
    routes.clear();
   
    return EXIT_SUCCESS;
}

