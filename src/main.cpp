//
// Created by Rafael Lima on 10/10/21.
//

#include <iostream>
#include "Game.h"

int main()
{
    auto game = Game::instance();
    game->start();
    return EXIT_SUCCESS;
}

