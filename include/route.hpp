#include <SFML/Graphics.hpp>
#include "point.hpp"
#include "algo/algo.hpp"

#ifndef ROUTE_HPP
#define ROUTE_HPP

typedef  unsigned int uint;

class Route{
    private:
        std::vector<uint>* arangement;
        double length;
        Point* points;
        sf::Color color;
        Algo* algo;
        uint id;
        uint pos;

    public:
        static uint count;

    public:
        Route();
        Route(std::vector<uint>* arangement, Point* points, sf::Color color);
        Route(Algo* algo, sf::Color color, uint pos=1);
        ~Route();
        void setColor(sf::Color color);
        void draw(sf::RenderWindow& window);
        double getLength();
        static double calcLength(std::vector<uint>& arangement,  Point* points);
};

#endif