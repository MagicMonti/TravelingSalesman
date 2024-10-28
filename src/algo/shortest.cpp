#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../../include/algo/shortest.hpp"
#include "../../include/route.hpp"


Point* Shortest::getNearest(Point* current, Point* points, std::vector<uint> valid){
    //valid = indeces which are valid
    double length = std::numeric_limits<double>::max() ;
    uint nearestIndex = 0;
    for (uint i = 0; i < valid.size() ; i++){
        double tempLenght = current->distanceToPoint(points[valid[i]]);
        if (tempLenght < length){
            length = tempLenght;
            nearestIndex = valid[i];
        }
    }
    return &(points[nearestIndex]);
}


std::vector<uint>* Shortest::calBestArangement(void){
    
 
    std::vector<uint> valid = this->arangement; 
    valid.erase(std::remove(valid.begin(), valid.end(), 0));
    this->tempArangement.push_back(0);

    Point* current = &(this->points[0]);

    for (uint i = 0 ; i < Point::count-1; i++){
        current = this->getNearest(current, this->points, valid);
        valid.erase(std::remove(valid.begin(), valid.end(), current->getId()));
        tempArangement.push_back(current->getId());
    }
    
    this->arangement = this->tempArangement;

  
    double length = Route::calcLength(this->arangement, this->points);

    this->setLabel("nearest", length);

    return &(this->tempArangement);
}