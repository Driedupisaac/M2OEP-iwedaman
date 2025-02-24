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
#include "Board.h"
#include <fstream>
#include "Tax.h"

class Player;

class Board {
public:
    std::vector<Square*> board;
    Board() {
        // Initialize the board with Street and tax objects
        board.push_back(new Street("GO!"));
        board.push_back(new Street("Mediterranean"));
        board.push_back(new Street("baltic"));
        board.push_back(new Tax("Income", 2000));
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
        board.push_back(new Tax("luxury", 75));
        board.push_back(new Street("Boardwalk"));

    }


    //method to represent a player's moving around the board
    void travel(Player& player, int position){
        //calls the Square object or it's inherited class' on() method, to say where the player is initially
        cout << "Hello, " << player.getName();
        board[player.getPosition()]->on();

        //prompt to tell the user what they rolled
        cout << " and have rolled a " << position;
        //updating player position, the following logic is to prevent overflow
        int total = player.getPosition() + position;
        if (total >= board.size()) {
            total %= board.size();
        }
        //updating the logic
        player.setPosition(total);

        //calling the inheritable land() method, from all squares. as of right now, the player is taxed if
        //they land on a tax square
        board[player.getPosition()]->land(player);
    }

    //this method is to represent a player's turn
    void turn(Player& player) {
        //boolean to check if a user has rolled or not, and int for their choice
        bool done = false;
        int choice;
        //prompt for their menu
        cout << "\nIts your turn, " << player.getName() << "! Please enter a 1 to roll & move, a two to check your assets, or a three to save the game!\n";
        cout << "you have " << player.getDollars() << " dollars\n";
        //menu logic, 1 for the user to roll the dice, two to show them their assets, and three to save game
        while(!done) {
            //input validation
            choice = get_int_from_user();
            while (choice != 1 && choice != 2 && choice != 3) {
                cout << "Please enter a choice, 1-3\n";
                choice = get_int_from_user();
            }
            //case 1: the player moves
            if (choice == 1) {
                travel(player, player.roll());
                done = true;
            }
            //case two, the player's assets are shown
            if (choice == 2) {
                cout << player.getAssets() << endl;
                cout << "\nIts your turn, " << player.getName() << "! Please enter a 1 to roll & move, a two to check your assets, or a three to save the game!\n";
                cout << "you have " << player.getDollars() << " dollars\n";
            }
            //case three: the player's character is saved, and input validation
            if (choice == 3) {
                cout << "what file do you want to save to?";
                string fileName = ("../"  + get_sentence_from_user());
                ofstream outputFile(fileName);

                outputFile << player.toString();


                outputFile.close();
                cout << "\nIts your turn, " << player.getName() << "! Please enter a 1 to roll & move, a two to check your assets, or a three to save the game!\n";
                cout << "you have " << player.getDollars() << " dollars\n";
            }
        }

    }

    //class destructor
    ~Board() {
        for (Square* s : board) {
            delete s;
        }
    }




};



#endif //BOARD_H
