#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include "Asset.h"
#include <string>

class Player {
private:
    std::string name;
    string dollars;
    std::vector<Asset> assets;

public:
    Player(string playerName);
    Player(string& playerName, string money, string assetOne, string assetTwo, string assetThree);

    std::string getName();
    std::int getDollars();
    std::nt assetsValue() const;
    std::string getAsset(int index);
    std::string getAssets();
    std::string toString();
    bool operator==(const Player& other) const;
};
#endif