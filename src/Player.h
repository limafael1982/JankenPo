//
// Created by Rafael Lima on 10/10/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>
#include <iostream>
#include "WeaponEnum.h"



class Player {

private:
    WeaponEnum weapon;
    std::string playerName;
    unsigned short int numPoints;
    unsigned short int maxPoints = 100;

public:

    Player(std::string playerName);
    Player();
    virtual ~Player();
    Player(const Player &other) = delete;
    std::string getPlayerName();
    void setPlayerName(std::string playerName);
    void setWeapon(int choice);
    WeaponEnum getWeapon();
    std::string getCurrentWeaponStr();
    unsigned short int getNumPoints();
    void increasePoints();
};

#endif // PLAYER_H
