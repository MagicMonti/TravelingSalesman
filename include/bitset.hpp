//#include <vector>


#ifndef BITSET_HPP
#define BITSET_HPP

typedef  unsigned int uint;

class BitSet{
    private:
        bool* bits;
        uint length;
    public:
        BitSet(uint length);
        ~BitSet();
        void operator<<=(int numberOfShifts); //shift left
        void operator>>=(int numberOfShifts); //shift right
        bool operator[](uint index); 
        void operator=(uint number);
        void operator=(BitSet& bits);
        bool operator==(BitSet& bits);
        bool operator==(uint number);
        bool operator!=(BitSet& bits);
        bool operator!=(uint number);

        //TODO bitwise ! % | operators 
        uint getLenght();
        void print();

        //shortcuts = performance boosts
        void setOne();
        bool isZero();
};

#endif