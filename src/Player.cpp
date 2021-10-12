//
// Created by Rafael Lima on 10/10/21.
//

#include "Player.h"

#include <utility>


Player::Player(std::string playerName)
{
    this->playerName = std::move(playerName);
    numPoints = 0;
    weapon = SCISSORS;
}

Player::Player()
{
    playerName = "Player 1";
    numPoints = 0;
    weapon = SCISSORS;
}

Player::~Player()
{
}

std::string Player::getPlayerName()
{
    return playerName;
}

void Player::setPlayerName(std::string playerName)
{
    this->playerName = std::move(playerName);
}

unsigned short int Player::getNumPoints()
{
    return numPoints;
}

void Player::increasePoints()
{
    if (numPoints < maxPoints)
    {
        numPoints++;
    }
}

WeaponEnum Player::getWeapon()
{
    return this->weapon;
}

std::string Player::getCurrentWeaponStr()
{
    std::string ans;
    switch (this->weapon)
    {
        case SCISSORS:
        {
            ans = "SCISSORS";
            break;
        }
        case PAPER:
        {
            ans = "PAPER";
            break;
        }
        case ROCK:
        {
            ans = "ROCK";
            break;
        }
    }

    return ans;
}

void Player::setWeapon(int choice)
{
    switch (choice)
    {
        case 1: {this->weapon = SCISSORS; break;}
        case 2: {this->weapon = PAPER; break;}
        case 3: {this->weapon = ROCK; break;}
        default :
        {
            std::string error_msg = "Please choose number 1, 2 or 3.";
            std::cout << error_msg << std::endl;
            throw std::invalid_argument(error_msg);
        }
    }
}

int Player::getRandomNumber(int lower_bound, int upper_bound)
{
    srand(time(NULL));
    int range = upper_bound - lower_bound + 1;
    return rand() % range + lower_bound;
}

void Player::setRandomWeapon()
{
    this->setWeapon(getRandomNumber(1, 3));
}
