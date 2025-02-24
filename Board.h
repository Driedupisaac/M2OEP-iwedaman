//
// Created by Isaac Wedaman on 2/21/25.
//
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Player.h"
#include "Square.h"
#include "Street.h"
#include "utility.h"

class Player;

class Board {
public:
    std::vector<Square*> board;
    Board() {
        // Initialize the board with Street objects
        board.push_back(new Street("GO!"));
        board.push_back(new Street("Mediterranean"));
        board.push_back(new Street("baltic"));
        board.push_back(new Street("RR1"));
        board.push_back(new Street("Oriental"));
        board.push_back(new Street("Vermont"));
        board.push_back(new Street("Connecticut"));

        board.push_back(new Street("St Charles"));
        board.push_back(new Street("Electric Company"));
        board.push_back(new Street("States"));
        board.push_back(new Street("VIrginia"));
        board.push_back(new Street("Railroad 2"));
        board.push_back(new Street("St James"));
        board.push_back(new Street("Tenessee"));
        board.push_back(new Street("New York"));

        board.push_back(new Street("Kentucky"));
        board.push_back(new Street("Water Company"));
        board.push_back(new Street("Indiana"));
        board.push_back(new Street("Illinois"));
        board.push_back(new Street("Railroad 3"));
        board.push_back(new Street("Atlantic"));
        board.push_back(new Street("Ventnor"));
        board.push_back(new Street("Marvin Gardens"));

        board.push_back(new Street("Pacific"));
        board.push_back(new Street("North Carolina"));
        board.push_back(new Street("Pennsylvania"));
        board.push_back(new Street("Railroad 4"));
        board.push_back(new Street("Park Place"));
        board.push_back(new Street("Boardwalk"));

    }



    void travel(Player& player, int position){
        cout << "Hello, " << player.getName();
        board[player.getPosition()]->on();
        cout << " and have rolled a " << position;
        int total = player.getPosition() + position;
        if (total >= board.size()) {
            total %= board.size();
        }
        player.setPosition(total);
        board[player.getPosition()]->land();
    }

    void turn(Player& player) {
        bool turn = true;
        int choice;
        cout << "\nIts your turn, " << player.getName() << "! Please enter a 1 to roll & move, a two to check your assets, or a three to save the game!\n";
        cout << "you have " << player.getDollars() << " dollars\n";
        choice = get_int_from_user();
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Please enter a choice, 1-3\n";
            choice = get_int_from_user();
        }
        if (choice == 1) {
            travel(player, player.roll());
        }
        if (choice == 2) {
            cout << player.getAssets() << endl;
        }
    }

    ~Board() {
        for (Square* s : board) {
            delete s;
        }
    }




};



#endif //BOARD_H
