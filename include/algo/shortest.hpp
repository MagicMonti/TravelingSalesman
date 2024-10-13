#include "../../include/point.hpp"
#include "algo.hpp"

#ifndef SHORTEST_HPP
#define SHORTEST_HPP


typedef unsigned int uint;


class Shortest : public Algo {
    using Algo::Algo; 
    public:
       std::vector<uint>* calBestArangement(void) override; 
       Point* getNearest(Point* current, Point* points, std::vector<uint> valid);
};


#endif