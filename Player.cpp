//
// Created by Isaac Wedaman on 2/19/25.
//
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Asset.h"
#include <vector>
#include "Player.h"
using namespace std;

//player class, representing a user player in monopoly
class Player {
private:
  //variables for the name, total dollar amount of the player portfolio, and their portfolio
  string name;
  string dollars;
  vector<Asset> assets;

 //constructors, one for a user's name, for when the game starts, and one for the user's
 //game progress, so their portfolio as well
 public:
   Player(string name){
     this->name = name;
     cout << "Hello, " << name << "! Welcome to Monopoly" << endl;
     }

  Player(string name, string dollars, string assetOne, string assetTwo, string assetThree){
     this->name = name;
     this->dollars = dollars;
     assets.push_back(Asset(assetOne));
     assets.push_back(Asset(assetTwo));
     assets.push_back(Asset(assetThree));
   }

  //getters
  string getName() {
     return name;
   }

  string getDollars() {
     return dollars;
   }

  //this method returns the total value of all the properties in the user's portfolio
  int assetsValue () const
  {
     int count = 0;
     for (Asset asset : assets) {
       count += asset.getRent();
     }
     return count;
   }

//this returns the value a particular asset in the user's portfolio
  string getAsset(int index) {
     return assets[index].getName();
   }

  //method for printing all the assets, used in this class' toString() method
  string getAssets() {
     string allAssets = "";
     for (Asset asset : assets) {
       allAssets += asset.getName() + ",";
     }
     return allAssets;
   }

  //to string method - prints out the name, portfolio amount, and assets of the user
  string toString() {
     return name + "," + dollars + "," + getAssets();
   }

  //the way to compare players is through the value of their portfolios, so Im overloading the
  //== operator to compare two players' portfolio values
  bool operator== (const Player& other) const
  {
     return this->assetsValue() == other.assetsValue();
  }

  };


#endif //PLAYER_H