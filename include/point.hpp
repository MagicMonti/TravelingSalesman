#include <string>
#include <SFML/Graphics.hpp>
#ifndef POINT_HPP
#define POINT_HPP


typedef  unsigned int uint;



class Point {
    public:
        static uint count;


    private:
        uint id;
        double position[2];
        bool isDummy = true;
        sf::Text name;

   /* public:
        static uint count;*/

    public:
    	Point();
        Point(uint id, double x, double y);
        Point(double x, double y);
        Point(uint id);
        ~Point();
        void draw(sf::RenderWindow& window);
        double distanceToPoint(Point& point);
        double* getPosition(void);
        uint getId(void);
        void print(void);
        static Point* createPoints(uint numberOfPoints);
        void operator+=(Point& point);
        void operator-=(Point& point);
        void operator/=(double number);
        std::string toString(void);
};


#endif 
