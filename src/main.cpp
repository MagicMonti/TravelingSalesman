#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <list>
#include <memory>
#include <chrono>
#include <thread>
#include <cmath>
#include "../include/point.hpp"
#include "../include/route.hpp"
#include "../include/consts.hpp"
#include "../include/bitset.hpp"
#include "../include/algo/algo.hpp"
#include "../include/algo/permutation.hpp"
#include "../include/algo/donothing.hpp"
#include "../include/algo/shortest.hpp"
#include "../include/algo/shortestN.hpp"
#include "../include/algo/nearestAvg.hpp"


void oneUP(BitSet *bits, uint numberOfRoutes){
    /*if(!bits->isZero()){
        *bits <<= 1;
    }else{
        //bits = 1;
        bits->setOne();
    }*/

    if(*bits == uint(pow(2, numberOfRoutes-1))){
        bits->setOne();
    }else{
        *bits <<= 1;
    }
}
void oneDown(BitSet *bits, uint numberOfRoutes){
    /*if(bits->isZero()){
        *bits = uint(pow(2, numberOfRoutes-1));
    }else{
        *bits >>= 1;
    }*/
    if (*bits == 1){
        *bits = uint(pow(2, numberOfRoutes-1));
    }else{
        *bits >>= 1;
    }
}




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
    ShortestN shortestN(points);
    NearestAvg nearestAvg(points);

    routes.emplace_back(Route(&perm, sf::Color::Green,1));
    routes.emplace_back(Route(&shortest, sf::Color::Yellow,2));
    routes.emplace_back(Route(&shortestN, sf::Color::Red,3));
    routes.emplace_back(Route(&nearestAvg, sf::Color::Blue,4));
  
    float dpiScale = consts::getDPIScaleFactor();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(consts::MAX_X*dpiScale, consts::MAX_Y*dpiScale), "Traveling Salesman", sf::Style::Default, settings);

    sf::View view = window.getDefaultView();
    view.setSize(window.getSize().x / dpiScale, window.getSize().y / dpiScale);
    view.setCenter(view.getSize() / 2.f);
    window.setView(view);


    /*std::vector<bool> bits(routes.size());
    setBoolVec(bits,0);
*/
    //std::cout<< "calc done\n";
    BitSet bits(routes.size()); //2 bits = 00
    bits.setOne();
   

    sf::Event event;

    


    while (window.isOpen()) {
        auto start = std::chrono::high_resolution_clock::now();
        
        window.clear();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        
            { //scope to not interfier with integers
                uint i = 0 ;
                for (auto& route : routes) {
                    if (bits[i]){
                        route.activate();
                    }else{
                        route.deActivate();
                    }
                    i++;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                   oneUP(&bits, routes.size());
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                   oneDown(&bits, routes.size());
                }    
                //mouse wheel handeling
                if (event.type == sf::Event::MouseWheelScrolled){
                    float delta = event.mouseWheelScroll.delta;
                    const sf::Mouse::Wheel wheel = event.mouseWheelScroll.wheel;
                    if (wheel == sf::Mouse::VerticalWheel){
                        std::cout << delta << "\n";
                        //a typical tick is +-1 
                        if (delta > 0 ){ 
                            oneUP(&bits, routes.size());
                        }
                        if (delta < 0){
                            oneDown(&bits, routes.size());
                        }
                    }
                }

            }
        }

        
        for (auto& route : routes) {
            route.draw(window);
        }
       
        for (uint i = 0; i < numberOfPoints; i++){
            points[i].draw(window);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        auto pause = 16-duration; //60FPS
        if (pause < 0){
            pause = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        window.display();
    }

    delete [] points;

    //algos.clear();
    routes.clear();
   
    return EXIT_SUCCESS;
}
