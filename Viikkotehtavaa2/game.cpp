#include "game.h"
#include <iostream>
#include <cstdlib>

Game::Game(int maxnum) {
    std::cout << "DEBUG: Game-konstruktori\n";

    this->maxnum = maxnum;
    count = 0;

    rnum = rand() % maxnum + 1;
}

void Game::play() {
    std::cout << "DEBUG: play() aloitettu\n";

    int num;

    while (true) {
        std::cout << "Anna luku: ";
        std::cin >> num;

        count++;

        if (rnum > num) {
            std::cout << "Lukusi on pienempi\n";
        }
        else if (rnum < num) {
            std::cout << "Lukusi on suurempi\n";
        }
        else {
            std::cout << "Lukusi on yhtäsuuri\n";
            break;
        }
    }

    printGameResult();
}

void Game::printGameResult() {
    std::cout << "DEBUG: printGameResult()\n";
    std::cout << "Arvasit oikein " << count << " yrityksellä\n";
}