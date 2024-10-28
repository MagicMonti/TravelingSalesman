#include <iostream>
#include "../../include/algo/algo.hpp"
#include "../../include/point.hpp"


Algo::Algo(){}

Algo::~Algo(){
    
    //delete [] this->arangement;
}

Algo::Algo(Point* points){
    this->points = points;
    for (uint i = 0 ; i < Point::count ; i++){
        this->arangement.push_back(i);
    }
}

Point* Algo::getPoints(void){
    return this->points;
}
std::string* Algo::getLabel(void){
    return &(this->label);
}
void Algo::setLabel(std::string name, double length){
    this->label = "min Length ("+name+"): " + std::to_string(length) + '\n'; 
    this->label += "Arangement: ";
    for (auto entry : this->arangement){
        this->label += std::to_string(entry) + " " ;
    }
    //this->label += "0\n";
    //this->label += std::to_string(this->arangement[0]);
    this->label += "\n";
    std::cout << label << std::endl;
}
void Algo::cyclicPermutation(){
    while (this->arangement[0] != 0){
        std::rotate(
            this->arangement.begin(), 
            this->arangement.begin() + 1,
            this->arangement.end()
        ); 
    }
}

