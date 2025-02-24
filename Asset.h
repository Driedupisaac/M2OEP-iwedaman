//
// Created by Isaac Wedaman on 2/19/25.
//
using namespace std;
#include <iostream>


#ifndef ASSET_H
#define ASSET_H
//class to represent the asset, or monopoly property, of a user, to be inherited from
class Asset {
protected:
    //variables for the name, rent, and cost for mortgage
    int cost;
    string name;
    int rent;

    // class  constructor
public:
    Asset(string name) {
        this->name = name;
    };
    Asset(string name, int rent, int cost){
        this->name = name;
        this->rent = rent;
        this->cost = cost;
    };

    //getters and setters
    string getName() const { return name; }
    virtual int getRent() const { return rent; }

    void setName(string name) { this->name = name; }
    void setRent(int rent) { this->rent = rent; }
};

#endif //ASSET_H
