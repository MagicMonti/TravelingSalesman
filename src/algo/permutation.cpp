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
    
 
    double length = std::numeric_limits<double>::max() ;
    this->tempArangement = this->arangement; //copy
    
    do {
     
        double tempLenght = Route::calcLength(this->arangement, this->points);
        if (tempLenght < length){
            length = tempLenght;
            this->tempArangement = this->arangement; //copy
        }
      
        
    } while (std::next_permutation(this->arangement.begin(), this->arangement.end()));

    this->setLabel("permutation", length);

    return &tempArangement;
}