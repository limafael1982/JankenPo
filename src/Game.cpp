//
// Created by Rafael Lima on 10/10/21.
//

#include "Game.h"

Game::Game() : turns(5), player1(std::unique_ptr<Player>(new Player("Player 1"))),
               player2( std::unique_ptr<Player>(new Player("CPU")))
{
}

Game::~Game()
{
}

void Game::printInstructions()
{
    std::cout << R"(******* "Janken Po!" Game " *******)" << std::endl;
    std::cout << "Choose your weapon while playing:" << std::endl;
    std::cout << "1 for SCISSORS" << std::endl;
    std::cout << "2 for PAPER" << std::endl;
    std::cout << "3 for ROCK" << std::endl <<std::endl;

    std::cout << R"(Type "q" to quit.)" << std::endl;

}



void Game::displayWeaponsFromPlayers()
{
    std::cout << this->player1->getPlayerName() << " has " << this->player1->getCurrentWeaponStr()
        << " and " << this->player2->getPlayerName() << " has " <<
        this->player2->getCurrentWeaponStr() << "!" << std::endl;
}

void Game::decideWinnerFromCurrentRound()
{
    WeaponEnum p1Weapon = this->player1->getWeapon();
    WeaponEnum p2Weapon = this->player2->getWeapon();

    displayWeaponsFromPlayers();

    if ((p1Weapon == PAPER) && (p2Weapon == ROCK))
    {
        this->player1->increasePoints();
        std::cout << this->player1->getPlayerName() << " WINS the round!" << std::endl;
    }
    else if ((p1Weapon == ROCK) && (p2Weapon == PAPER))
    {
        this->player2->increasePoints();
        std::cout << this->player2->getPlayerName() << " WINS the round!" << std::endl;
    }
    else if ((p1Weapon == ROCK) && (p2Weapon == SCISSORS))
    {
        this->player1->increasePoints();
        std::cout << this->player1->getPlayerName() << " WINS the round!" << std::endl;
    }
    else if ((p1Weapon == SCISSORS) && (p2Weapon == ROCK))
    {
        this->player2->increasePoints();
        std::cout << this->player2->getPlayerName() << " WINS the round!" << std::endl;
    }
    else if ((p1Weapon == SCISSORS) && (p2Weapon == PAPER))
    {
        this->player1->increasePoints();
        std::cout << this->player1->getPlayerName() << " WINS the round!" << std::endl;
    }
    else if ((p1Weapon == PAPER) && (p2Weapon == SCISSORS))
    {
        this->player2->increasePoints();
        std::cout << this->player2->getPlayerName() << " WINS the round!" << std::endl;
    }
    else
    {
        std::cout << "DRAW game round!" << std::endl;
    }
}

void Game::displayPointsFromPlayers()
{
    std::cout << "[POINTS " << this->player1->getPlayerName()
        << "] = " << this->player1->getNumPoints() << std::endl;
    std::cout << "[POINTS " << this->player2->getPlayerName()
        << "] = " << this->player2->getNumPoints() << std::endl;
}

void Game::decideWinner()
{
    std::string winner = "DRAW GAME!";
    if ((this->player1->getNumPoints()) > (this->player2->getNumPoints()))
    {
        winner = player1->getPlayerName();
    }
    else if ((this->player2->getNumPoints()) > (this->player1->getNumPoints()))
    {
        winner = player2->getPlayerName();
    }

    std::cout << "Winner is: " << winner << std::endl;
}

void Game::start()
{
    printInstructions();
    while (this->turns > 0)
    {
        std::cout << "Choose: 1, 2, 3, or \"q\":";
        int option;
        std::cin >> option;
        if ((option == 1) || (option == 2) || (option == 3))
        {
            try
            {
                this->player1->setWeapon(option);
                this->player2->setRandomWeapon();

                decideWinnerFromCurrentRound();
                displayPointsFromPlayers();

            } catch (std::exception &e)
            {
                this->turns = 0;
                std::cout << "an error has occurred: " << e.what() << std::endl;
                break;
            }
            this->turns--;
        }
        else
        {
            this->turns = 0;
            break;
        }
    }
    displayPointsFromPlayers();
    decideWinner();
}

void Game::setTurns(int turns)
{
    this->turns = turns;
}


