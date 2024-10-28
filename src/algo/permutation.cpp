#include <iostream>
#include <boost/range/irange.hpp>
#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>
#include "../../include/algo/permutation.hpp"
#include "../../include/route.hpp"
#include <limits>



uint factorial(uint n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}



std::vector<uint>* Permutation::calBestArangement(void){
    
 
    double length = __DBL_MAX__ ;
    this->tempArangement = this->arangement; //copy
    
    do {
     
        double tempLenght = Route::calcLength(this->tempArangement, this->points);
        if (tempLenght < length){
            length = tempLenght;
            this->arangement = this->tempArangement; //copy
        }
      
        
    } while (std::next_permutation(this->tempArangement.begin(), this->tempArangement.end()));
    this->cyclicPermutation();
    this->setLabel("permutation", length);

    return &this->arangement;
}