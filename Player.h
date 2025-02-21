#include <vector>
#include "Asset.h"

class Player {
private:
    std::string name;
    int dollars;
    std::vector<Asset> assets;

public:
    explicit Player(const std::string& playerName);
    Player(const std::string& playerName, int money, const std::vector<Asset>& playerAssets);

    const std::string& getName() const;
    int getDollars() const;
    int assetsValue() const;
    const Asset& getAsset(size_t index) const;
    std::string getAssets() const;
    std::string toString() const;
    bool operator==(const Player& other) const;
};