//
// Created by Isaac Wedaman on 2/19/25.
//
using namespace std;
#include <iostream>


#ifndef ASSET_H
#define ASSET_H
//class to represent the asset, or monopoly property, of a user
class Asset {
private:
    //variables for the name, rent, and house count, and mortgage
    string name;
    int rent;
    int houseCount;
    int mortgage;

    // class  constructor
public:
    Asset(string name) {
        this->name = name;
    };

    //getters and setters
    string getName() const{
        return name;
    }

    int getRent() const {
        return rent;
    }

    void setName(string name) {
        this->name = name;
    }

    void setRent(int rent) {
        this->rent = rent;
    }

};

#endif //ASSET_H