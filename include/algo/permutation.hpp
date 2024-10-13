#include "../../include/point.hpp"
#include "algo.hpp"

#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP


typedef unsigned int uint;


class Permutation : public Algo {
    using Algo::Algo; 
    public:
       std::vector<uint>* calBestArangement(void) override; 
};


#endif