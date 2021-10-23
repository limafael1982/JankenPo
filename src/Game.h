//
// Created by Rafael Lima on 10/10/21.
//

#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <iostream>

#include "Player.h"

class Game
{
private:
    static Game* game_instance;
    int turns;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

    Game();

protected:
    void printInstructions();
    void decideWinnerFromCurrentRound();
    void displayWeaponsFromPlayers();
    void decideWinner();
    void displayPointsFromPlayers();

public:

    virtual ~Game();

    Game(const Game& game) = delete;
    Game& operator=(const Game& game) = delete;

    static std::shared_ptr<Game> instance()
    {
        static std::shared_ptr<Game> game{new Game};
        return game;
    };


    void setTurns(int turns);
    void start();

};


#endif // GAME_H_
