//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Asset.h"



class Property : public Asset{
  private:
    //for number of Properties present
    int count;
    //for houses, 5 for hotel
    int houses;
public:
    Property(string name, int rent, int cost)
        : Asset(name, rent, cost){}

    int getRent() const override {
        if (houses == 0) {
            return rent;
        }
        else {
            return rent * houses;
        }
    }

};



#endif //PROPERTY_H
