//
// Created by Isaac Wedaman on 2/23/25.
//

#ifndef TAX_H
#define TAX_H

#include "Square.h"
#include <iostream>
using namespace std;

//class to represent a tax square - a tax square is-a square
class Tax : public Square {
    //cost variable
    int landCost;
public:
    //class constructor
    explicit Tax(const std::string& name, int cost) : Square(name), landCost(cost) {}

    //overloading the land function to tax the player if they land on this one
    void land(Player& player) override {
        cout << "\nYouve landed on " << name;
        cout << " And are taxed " << landCost << " dollars. Your new balance is " << player.getDollars() - landCost << " dollars." << endl;
        player.setDollars(player.getDollars() - landCost);
    }

    //overriden method to say when a square is landed on
    void on() override {
        cout << " you are on " + name;
    }

};



#endif //TAX_H
