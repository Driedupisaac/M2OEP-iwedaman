//
// Created by Isaac Wedaman on 2/23/25.
//

#ifndef TAX_H
#define TAX_H

#include "Square.h"
#include <iostream>
using namespace std;



class Tax : public Square {
    int landCost;
public:
    explicit Tax(const std::string& name, int cost) : Square(name), landCost(cost) {}


    void land(Player& player) override {
        cout << "\nYouve landed on " << name;
        cout << " And are taxed " << landCost << " dollars. Your new balance is " << player.getDollars() - landCost << " dollars." << endl;
        player.setDollars(player.getDollars() - landCost);
    }

    void on() override {
        cout << " you are on " + name;
    }
    void on(int tax) {
        on();

    }
};



#endif //TAX_H
