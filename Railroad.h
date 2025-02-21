//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef RAILROAD_H
#define RAILROAD_H

#include "Asset.h"
#include <cmath>



class Railroad: public Asset {
private:
    //for number of Properties present
    int count;
public:
    Railroad(string name, int rent, int cost)
        : Asset(name, rent, cost){}

    int getRent() const override {
        return rent * pow(2, count);
    }
};



#endif //RAILROAD_H
