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

short int Player::getNumPoints()
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
