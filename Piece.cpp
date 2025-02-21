//
// Created by Isaac Wedaman on 2/21/25.
//

#include "Piece.h"
#include <string>
using namespace std;

Piece::Piece(string description, int startPosition) : description(description), position(startPosition) {}

string Piece::getDescription() const {
    return description;
}

int Piece::getPosition() const {
    return position;
}

void Piece::setPosition(int position) {
    this->position = position;
}

void Piece::move(int steps) {
    position = (position + steps) % 40; // Assume a standard 40-space Monopoly board
}

void Piece::displayInfo() const {
}