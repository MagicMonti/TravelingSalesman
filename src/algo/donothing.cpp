#include <iostream>
#include "../../include/algo/donothing.hpp"



std::vector<uint>* DoNothing::calBestArangement(void){
    this->setLabel("do nothing", 0);
    return &(this->arangement);
}