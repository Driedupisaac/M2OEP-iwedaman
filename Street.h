//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef STREET_H
#define STREET_H
#include "Player.h"
#include "Asset.h"
#include "Square.h"

//this class is meant to represent the normal street of a monopoly property
class Street : public Square {
    //variable for being owned
    bool own = false;
public:
    //class constructor
    explicit Street(const std::string& name) : Square(name) {}

    //to simulate the player landing on the property, inherited
    void land(Player& p) override {
        cout << "\nYouve landed on " << name << endl;
    }

    //inherited method for starting on a property
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
