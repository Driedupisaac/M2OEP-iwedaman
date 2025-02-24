//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef SQUARE_H
#define SQUARE_H
#include <string>



class Square {
public:
    string name;
    explicit Square(const std::string& name) : name(name) {}
    virtual void land() {
        cout << "I've been landed on!";
    }
    virtual void on() {
        cout<< "Im on!";
    }
};



#endif //SQUARE_H
