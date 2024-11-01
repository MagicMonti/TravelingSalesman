#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../../include/algo/nearestAvg.hpp"
#include "../../include/route.hpp"
#include "../../include/consts.hpp"



std::vector<uint>* NearestAvg::calBestArangement(void){
    
    double length = __DBL_MAX__;
    double temp ;
    
    
  

    for (uint j = 0 ; j < Point::count-1; j++){
    
        std::vector<uint> valid = this->arangement; 
        valid.erase(std::remove(valid.begin(), valid.end(), j));
        this->tempArangement.clear();
        this->tempArangement.push_back(j);
        Point* current = &(this->points[j]);

        this->averagePoint = new Point(0,0); //<- no Point::count++



        for (uint i = 0 ; i < Point::count-1; i++){
            Point* nearest = this->getNearest(current, this->points, valid);
            
            this->avgPoint(nearest->getId(), current->getId(), valid);

            double nearestDistance = current->distanceToPoint(*nearest);
            double avgDistance = current->distanceToPoint(*(this->averagePoint));
            if (avgDistance < nearestDistance){
                valid.erase(std::remove(valid.begin(), valid.end(), nearest->getId())); //removes nearest from valid points
                
                current = this->getNearest(this->averagePoint, this->points, valid);
                if (current != nullptr){
                    valid.push_back(nearest->getId()); //add nearest again since it should be posible to reach it in the comming iterations.
                }else{
                    current = nearest;
                }
            
            
            }else{
                current = nearest;
            }

            valid.erase(std::remove(valid.begin(), valid.end(), current->getId()));
            tempArangement.push_back(current->getId());
        }
        temp = Route::calcLength(tempArangement, this->points);
        if (temp < length){
            length = temp;
        }

        delete this->averagePoint;
    }



    this->arangement = this->tempArangement;
    

    this->cyclicPermutation();
    this->setLabel("nearest-avg-N", length);
    


    return &(this->arangement);
}

void NearestAvg::avgPoint(uint nearestId, uint currentId, std::vector<uint> valid){
    int counter = 1;
    for (uint i = 0 ; i < Point::count-1; i++){
        if (
            (this->points[i].getId() != nearestId) && 
            (this->points[i].getId() != currentId) &&
            (consts::isIn(this->points[i].getId(), valid))
        ){
            *(this->averagePoint) += this->points[i];
            counter++;
        }
       
    }
    *(this->averagePoint) /= counter;
}

