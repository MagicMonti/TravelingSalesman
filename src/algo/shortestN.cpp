#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../../include/algo/shortestN.hpp"
#include "../../include/route.hpp"



std::vector<uint>* ShortestN::calBestArangement(void){
    
    double length = __DBL_MAX__;
    double temp ;
    for (uint j = 0 ; j < Point::count-1; j++){
    
        std::vector<uint> valid = this->arangement; 
        valid.erase(std::remove(valid.begin(), valid.end(), j));
        this->tempArangement.clear();
        this->tempArangement.push_back(j);
        Point* current = &(this->points[j]);

        for (uint i = 0 ; i < Point::count-1; i++){
            current = this->getNearest(current, this->points, valid);
            valid.erase(std::remove(valid.begin(), valid.end(), current->getId()));
            tempArangement.push_back(current->getId());
        }
        temp = Route::calcLength(tempArangement, this->points);
        if (temp < length){
            length = temp;
        }
    }

    this->arangement = this->tempArangement;
    

    this->cyclicPermutation();
    this->setLabel("nearest-N", length);

    return &(this->tempArangement);
}