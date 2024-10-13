#include <iostream>
#include "../include/route.hpp"
#include "../include/point.hpp"
#include "../include/consts.hpp"

uint Route::count = 0;

Route::Route(){
    Route::count++;
    this->id = Route::count;
    this->length = 0;
    //this->color = sf::Color::White;
   
    this->points = nullptr;
}
Route::Route(std::vector<uint>* arangement,  Point* points, sf::Color color){
    this->id = ++Route::count;
    this->arangement = arangement;
    this->length = 0;
    this->color = color;
    this->points = points;
   
}
Route::Route(Algo* algo, sf::Color color, uint pos){
    this->id = ++Route::count;
    this->algo = algo;
    this->pos = pos;
    this->arangement = algo->calBestArangement();
    this->length = 0;
    this->color = color;
    this->points = algo->getPoints();
}



Route::~Route(){
    Route::count--;
    //std::cout << "delete route" << '\n';
}

void Route::setColor(sf::Color color){
    this->color = color;
}

void Route::draw(sf::RenderWindow& window){
    uint index_1;
    uint index_2;
    float p1x, p1y ,p2x, p2y;
    for(uint i = 0; i < Point::count-1 ; i++){

        index_1 = (*(this->arangement))[i];
        index_2 = (*(this->arangement))[i+1];
        this->length += points[index_1].distanceToPoint(this->points[index_2]);
        p1x = float(points[index_1].getPosition()[0]);
        p1y = float(points[index_1].getPosition()[1]);
        p2x = float(points[index_2].getPosition()[0]);
        p2y = float(points[index_2].getPosition()[1]);
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(p1x, p1y)),
            sf::Vertex(sf::Vector2f(p2x, p2y))
        };
        line->color = this->color;
        window.draw(line, 2, sf::Lines);

        if (this->algo != nullptr){
            sf::Text label;
            label.setString(*(this->algo->getLabel()));
            label.setFont(consts::font_2);
            label.setCharacterSize(20);
            label.setFillColor(sf::Color::White);
            label.setPosition(20,consts::MAX_Y-60*this->pos- 10);
            window.draw(label);
        }
        
    }
    
    p1x = float(points[index_2].getPosition()[0]);
    p1y = float(points[index_2].getPosition()[1]);
    p2x = float(points[0].getPosition()[0]);
    p2y = float(points[0].getPosition()[1]);
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(p1x, p1y)),
        sf::Vertex(sf::Vector2f(p2x, p2y))
    };
    line->color = this->color;
    window.draw(line, 2, sf::Lines);

}
//static
double Route::calcLength(std::vector<uint>& arangement, Point* points){
    float length = 0;
    uint index_1;
    uint index_2;
    //0 is always the start and the end
    length += points[0].distanceToPoint(points[arangement[0]]);
    for(uint i = 0; i < Point::count-1 ; i++){
        index_1 = arangement[i];
        index_2 = arangement[i+1];
        length += points[index_1].distanceToPoint(points[index_2]);
    }
    //closing 
    length += points[index_2].distanceToPoint(points[0]);

    
    return length;
 }


double Route::getLength(void){
    this->length = Route::calcLength(*(this->arangement),this->points);
    return this->length;
}

