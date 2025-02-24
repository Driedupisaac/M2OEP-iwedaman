//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef ELECWATER_H
#define ELECWATER_H
#include "Asset.h"


//Type of Asset to represent the Electric Company and Water company utilities
class ElecWater : Asset {
private:
    //for number of Properties present
    int count;
    int roll;
public:
    //constructor
    ElecWater(string name, int rent, int cost)
        : Asset(name, rent, cost){}

    //overloaded getRent Function
    int getRent() const override {
        return roll * rent;
    }

};



#endif //ELECWATER_H
