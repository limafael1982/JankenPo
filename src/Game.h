//
// Created by Rafael Lima on 10/10/21.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include <iostream>
#include "Player.h"

class Game
{
private:
    int turns;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

protected:
    int getRandomNumber(int lower_bound, int upper_bound);
    void printInstructions();
    void decideWinnerFromCurrentRound();
    void displayWeaponsFromPlayers();
    void decideWinner();
    void displayPointsFromPlayers();

public:
    Game(int turns);
    Game();
    virtual ~Game();

    void start();

};


#endif // GAME_H
