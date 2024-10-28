#include "../../include/point.hpp"
#include "shortest.hpp"

#ifndef SHORTESTN_HPP
#define SHORTESTN_HPP


typedef unsigned int uint;


class ShortestN : public Shortest {
    using Shortest::Shortest; 
    public:
       std::vector<uint>* calBestArangement(void); 
};


#endif