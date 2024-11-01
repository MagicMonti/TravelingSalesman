#include "../../include/point.hpp"
#include "shortest.hpp"

#ifndef NEARESTAVG_HPP
#define NEARESTAVG_HPP


typedef unsigned int uint;


class NearestAvg: public Shortest {
    using Shortest::Shortest; 

    private:
        Point* averagePoint;

    public:
       std::vector<uint>* calBestArangement(void);
       void avgPoint(uint neareestId, uint currentId, std::vector<uint> valid); 
};


#endif