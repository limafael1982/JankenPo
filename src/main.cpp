//
// Created by Rafael Lima on 10/10/21.
//

#include <iostream>
#include "Player.h"

int main()
{
    std::cout << "Example" << std::endl;
    Player p1;
    Player p2("Player 2");

    std::cout << p1.getPlayerName() << " " << p2.getPlayerName() << std::endl;
    return EXIT_SUCCESS;
}

