//
// Created by Isaac Wedaman on 2/21/25.
//

#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;



class Piece {
private:
    string description;
    int position;

public:
    Piece(string description, int startPosition = 0);

    string getDescription() const;

    int getPosition() const;
    void setPosition(int position);
    void move(int steps);

    void displayInfo() const;
};



#endif //PIECE_H
