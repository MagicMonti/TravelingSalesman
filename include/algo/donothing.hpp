#include "../../include/point.hpp"
#include "algo.hpp"

#ifndef DONOTHING_HPP
#define DONOTHING_HPP


typedef unsigned int uint;


class DoNothing : public Algo {
    using Algo::Algo;
    public:
       std::vector<uint>* calBestArangement(void) override; 
};

#endif

