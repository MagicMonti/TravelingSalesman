#include <iostream>
#include <cmath>
#include <boost/random.hpp>
#include <SFML/Graphics.hpp>
#include "../include/point.hpp"
#include "../include/consts.hpp"


uint Point::count = 0;


Point::Point(){
    Point::count++;
    this->id = 0;
    this->isDummy = true;
    //std::cout << "create default Point " << this->isDummy << '\n';
    
}

Point::Point(uint id){
    Point::count++;
    this->id = id;
    this->name.setString(std::to_string(this->id));
    this->name.setFont(consts::font);
    this->name.setCharacterSize(30);
    this->name.setFillColor(sf::Color::White);
    //this->name.setStyle(sf::Text::Bold | sf::Text::Underlined);

    this->isDummy = false;
   
    boost::random::mt19937 rng;
    rng.seed(static_cast<unsigned int>(std::time(0) + id));

    boost::random::uniform_real_distribution<double> dist_1(consts::MAX_X/2, consts::MAX_X-20);
    boost::random::uniform_real_distribution<double> dist_2(20, consts::MAX_Y-20);
    this->position[0] = dist_1(rng) ;
    this->position[1] = dist_2(rng) ;

    //std::cout << "create random Point " <<this->id<< '\n';

}
Point::Point(uint id, double x , double y){
    Point::count++;
    this->id = id;
    this->position[0] = x;
    this->position[1] = y;
}
Point::~Point(){
    Point::count--;
    //std::cout << "deleting " << this->id <<"|" << this->isDummy << '\n';
}



double* Point::getPosition(void){
    return this->position;
}
uint Point::getId(void){
    return this->id;
}

double Point::distanceToPoint(Point& point){
    double deltaX = this->position[0] - point.getPosition()[0];
    double deltaY = this->position[1] - point.getPosition()[1];
    return sqrt( pow(deltaX,2) + pow(deltaY,2));
    //return pow(deltaX,2) + pow(deltaY,2);
}
void Point::print(){
    std::cout << this->position[0] << " , " << this->position[1] << '\n';
}

Point* Point::createPoints(uint numberOfPoints){
    Point* points = new Point[numberOfPoints];

    for(uint i = 0; i < numberOfPoints ; i++){
        points[i] = Point(i);
        //points[i].print();
    }
    return points;
}

void Point::draw(sf::RenderWindow& window){
    sf::CircleShape point(5);
    point.setFillColor(sf::Color::Red); 
    point.setPosition(this->position[0]-3, this->position[1]-3); 
    this->name.setPosition(this->position[0]-20, this->position[1]-20);
    window.draw(this->name);
    window.draw(point); 
}
