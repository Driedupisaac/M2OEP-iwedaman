//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef SQUARE_H
#define SQUARE_H
#include <string>
#include "Player.h"


//virtual class to represent a square on the monopoly board - to be inherited from
class Square {
public:
    //variable for name
    string name;

    //class constructor
    explicit Square(const std::string& name) : name(name) {}

    //virtual land method, if this square was landed on
    virtual void land(Player& player) {
        cout << "I've been landed on!";
    }

    //virtual method to represent starting on this square
    virtual void on() {
        cout<< "Im on!";
    }
};



#endif //SQUARE_H
