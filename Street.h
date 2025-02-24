//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef STREET_H
#define STREET_H
#include "Player.h"
#include "Asset.h"
#include "Square.h"


class Street : public Square {
    bool own = false;
    //Player owner;
    //Asset asset;
public:
    explicit Street(const std::string& name) : Square(name) {}

    //to simulate the player buying a property
    void land() override {
        cout << "\nYouve landed on " << name << endl;
    }

    void on() override {
        cout << " you are on " + name;
    }
};

    // void buy(Player player) {
    //     if(!this.own) {
    //         player.setDollars()
    //     }
    // }}







#endif //STREET_H
