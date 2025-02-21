//
// Created by Isaac Wedaman on 2/19/25.
//
#include "Player.h"
#include "Asset.h"
#include <iostream>
#include <stdexcept>

Player::Player(const std::string& playerName)
    : name(playerName), dollars(1500) {
    std::cout << "Hello, " << name << "! Welcome to Monopoly.\n";
}

Player::Player(const std::string& playerName, int money, const std::vector<Asset>& playerAssets)
    : name(playerName), dollars(money), assets(playerAssets) {}

const std::string& Player::getName() const { return name; }
int Player::getDollars() const { return dollars; }

int Player::assetsValue() const {
    int totalValue = 0;
    for (const auto& asset : assets) {
        totalValue += asset.getRent();
    }
    return totalValue;
}

const Asset& Player::getAsset(size_t index) const {
    if (index < assets.size()) {
        return assets[index];
    }
    throw std::out_of_range("Asset index out of range.");
}

std::string Player::getAssets() const {
    std::string assetList;
    for (size_t i = 0; i < assets.size(); ++i) {
        assetList += assets[i].getName();
        if (i < assets.size() - 1) {
            assetList += ", ";
        }
    }
    return assetList.empty() ? "No assets" : assetList;
}

std::string Player::toString() const {
    return name + ", $" + std::to_string(dollars) + ", Assets: [" + getAssets() + "]";
}

bool Player::operator==(const Player& other) const {
    return assetsValue() == other.assetsValue();
}