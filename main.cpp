//
// Created by Isaac Wedaman on 2/19/25.
//
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Player.h"

using namespace std;


//my goal here is to make some sort of monopoly game, and hopefully build on the project there

int main() {
    cout << "welcome to monopoly!" << endl ;

    //initializing a game instance, and running the game function
    Game game;
    game.start();

    return 0;
}
