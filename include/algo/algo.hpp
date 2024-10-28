#include "../../include/point.hpp"


#ifndef ALGO_HPP
#define ALGO_HPP


typedef unsigned int uint;

class Algo{
  
    protected:
        Point* points;
        std::vector<uint> arangement; //no reference, actual values 
        std::vector<uint> tempArangement;
        std::string label = "";

    protected:
        void cyclicPermutation();
        

    public:
        Algo();
        virtual ~Algo();
        Algo(Point* points);
        virtual std::vector<uint>* calBestArangement(void)= 0;
        Point* getPoints(void);
        void setLabel(std::string name, double length);
        std::string* getLabel(void);

};


#endif
