//
// Created by Rafael Lima on 10/10/21.
//

#include "Game.h"


Game::Game(unsigned short turns)
{
    this->turns = turns;
    this->player1 = std::unique_ptr<Player>(new Player("Player 1"));
    this->player2 = std::unique_ptr<Player>(new Player("CPU"));
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

int Game::getRandomNumber(int lower_bound, int upper_bound)
{
    srand(time(NULL));
    int range = upper_bound - lower_bound + 1;
    return rand() % range + lower_bound;
}

void Game::displayWeaponsFromPlayers()
{
    std::cout << this->player1->getPlayerName() << " has " << this->player1->getCurrentWeaponStr()
        << " and " << this->player2->getPlayerName() << " has " <<
        this->player2->getCurrentWeaponStr() << "!";
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
        unsigned char option;
        std::cin >> option;
        if (option == 'q')
        {
            this->turns = 0;

        }
        else
        {
            try
            {
                this->turns--;
                int option_num = static_cast<int>(option);
                this->player1->setWeapon(option_num);
                this->player2->setWeapon(this->getRandomNumber(1, 3));
                decideWinnerFromCurrentRound();

            } catch (std::exception &e)
            {
                this->turns = 0;
                std::cout << "an error has occurred: " << e.what() << std::endl;
                break;
            }
            this->turns--;
        }
    }
    decideWinner();
}
