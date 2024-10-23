#include <cmath>
#include <iostream>
#include "../include/bitset.hpp"

BitSet::BitSet(uint length){
    this->length = length;
    this->bits = new bool[length];
    for (uint i = 0; i < length; i++){
        this->bits[i] = 0;
    }
}
BitSet::~BitSet(){
    delete [] this->bits;
}

uint BitSet::getLenght(){
    return this->length;
}
void BitSet::print(){
    for (int j = this->length-1; j >= 0  ; j--){
        std::cout << this->bits[j];
    }
    std::cout << '\n';
}

/*----------operators-----------*/
void BitSet::operator<<=(int numberOfShifts){
    
    for (int j = this->length-1; j >= 0 ; j--){
        if ((j-numberOfShifts) >= 0){
            //std::cout << j <<" " <<  (j-numberOfShifts)<<  '\n';
            this->bits[j] = this->bits[j-numberOfShifts];
        } else{
            this->bits[j] = 0;
        }
    }
   
}
void BitSet::operator>>=(int numberOfShifts){
    for (uint i = 0; i < this->length ; i++){
        if ((i + numberOfShifts) < this->length){
            this->bits[i] = this->bits[i + numberOfShifts];
        }else{
            this->bits[i] = 0;
        }
    }
}
bool BitSet::operator[](uint index){
    return this->bits[index];
}
void BitSet::operator=(uint number){
    if (number >= pow(2,this->length)-1){
        for (int j = this->length-1 ; j >= 0;j-- ){
           this->bits[j] = 1; 
        }
    } else{
        uint divisor = 2;
        for (uint i = 0 ; i < this->length;i++ ){
            this->bits[i] = number % divisor;
            if (this->bits[i]){
                number--; 
            }
            divisor *= 2;
        }
    }
}
void BitSet::operator=(BitSet& bits){ //copy values
    this->bits = bits.bits;
    this->length = bits.getLenght();
}


bool BitSet::operator==(BitSet& bits){
    for (uint i = 0; i < length; i++){
        if (this->bits[i] != bits[i] ){
            return false;
        }
    }
    return true;
}
bool BitSet::operator==(uint number){
    if (number > pow(2,this->length)-1){
        return false; //number is bigger than it can be represented in bitset, so it is therefore clearly not equal
    }else{
        uint count=0;
        for (uint i = 0 ; i < this->length;i++ ){
            if (this->bits[i]){
                count += pow(2,i);
            }
        }
        return (count == number);
    }

}
bool BitSet::operator!=(BitSet& bits){
    for (uint i = 0; i < this->length; i++){
        if (this->bits[i] == bits[i] ){
            return false;
        }
    }
    return true;
}
bool BitSet::operator!=(uint number){
    if (number > pow(2,this->length)-1){
        return false; //number is bigger than in can be represented in bitset so it is therefore clearly not equal
    }else{
        uint count=0;
        for (uint i = 0 ; i < this->length;i++ ){
            if (!(this->bits[i])){
                count += pow(2,i);
            }
        }
        return (count == number);
    }
}

void BitSet::setOne(){
    for (uint i = 0; i < length; i++){
        if (i != 0){
            this->bits[i] = 0;
        } else{
            this->bits[i] = 1;
        }
        
    }
}
bool BitSet::isZero(){
    for (uint i = 0; i < this->length; i++){
        if (this->bits[i]){
            return false;
        }
    }
    return true;
};
