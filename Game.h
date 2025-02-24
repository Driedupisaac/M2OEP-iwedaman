//
// Created by Isaac Wedaman on 1/29/25.
//
#include <iostream>
#include <sstream>
#include <string>
#include "Asset.h"
#include <vector>
#include "Player.h"
#include <fstream>
#include "utility.h"
#include "Board.h"
using namespace std;

//game class, where the game is played, to keep the main function uncluttered
class Game {
private:
  //vector of Players, to keep track of them
  //Initialization of the board class
  vector<Player> players;
  Board board;

public:
  //the method for starting the game
  void start() {
    //count represents the input of the user for a text based menu
    int count = 0;

    //the count variable represents a saved game [1] or a new game [0]
    //input validation, using the userInt methodfrom the utility.cpp file
    count = userInt("Please enter a 1 for a saved game, or a 0 for a new one");
    while (count != 1 && count != 0) {
      count = userInt("Please enter a 1 for a saved game, or a 0 for a new one");
    }

    /*
    *if the user wants a new game, they are asked how many are playing, and then each player
    *is prompted to enter their name, after which a player obect is created for them and added
    *into the players vector
    */
    if (count == 0) {
      count = userInt("Welcome to Monopoly! How many are playing?");
      while (count < 1 || count > 4){
        cout << "Please enter number less than 5" << endl;
        count = userInt("How many are playing?");
      }

       //creating the player instances for each player
       for(int i = 0; i < count; i++){
         string input;
         cout << "Hello, " << "player " << i+1 << "! What is your name: ";
         input = get_sentence_from_user();
         players.push_back(Player(input));
       }


      //basic game loop
      while(true) {
        for(Player& player : players) {
          board.turn(player);
        }
      }

      cout << players[0].toString();

    }

    //the case that there was a saved game to load
    else {
       //prompting the user to enter their filename, and validating that it exists
       cout << "please enter a file to open from! ";
       string fileName = ("../"  + get_sentence_from_user());
       ifstream file(fileName);

       //input validation
       while(!file) {
         cout << "There was an error opening the file! please enter the name again: ";
         file.clear();

         fileName = ("../" + get_sentence_from_user());
         file.open(fileName);
       }


       //one player at a time, the vector takes all the input, and we can use logic later to sort
       //through it, for now all will be equal length
       vector<string> inputs;


      string user;
      getline(file, user);
      string item;
      stringstream ss(user);
      string line;

      while (getline(file, line)) {

        stringstream ss(line);
        string item;
        vector<string> inputs;

        while (getline(ss, item, ',')) {
          inputs.push_back(item);
        }
      }

       //getting the information from the file, creating a player instance, and closing the file
       //the protocol will be that the first two items are the player name and money count,
       //and the rest, all equal per player as an input protocol, will be properties
       // players.push_back(Player(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]));
       // //closing the file
       // file.close();
       //
       //writing to a file, in the instance we need to save the game
       ofstream outputFile("../test1.txt");

       for(Player player : players) {
         outputFile << player.toString() << endl;
       }

       outputFile.close();

    }

  }

  //toString method for writing to a vector
  string toString(vector<Player> players) {
    string out = "";
    for(Player player : players) {
      out += player.toString() + "\n";
    }
    return out;
  }

  //method for getting input validated - making sure that its an integer
  int userInt(string in) {
    string input;
    int integer;
    bool checker = false;

    //getting input
    cout << in << ": ";
    getline(cin, input);

    //turning input to a stringstream, and reading an integer into it
    stringstream ss(input);
    if (ss >> integer) {
      checker = true;
    }

    //while loop for input validation
    while (!checker) {
      cout << "Invalid! -  Please enter an integer: ";
      getline(cin, input);

      stringstream ss(input);
      if (ss >> integer) {
        checker = true;
      }
    }
    return integer;
  }
};

#ifndef GAME_H
#define GAME_H

#endif //GAME_H