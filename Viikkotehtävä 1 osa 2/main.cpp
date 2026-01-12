#include <iostream>
#include <cstdlib>
#include <ctime>


int game(int maxnum) {
    int arvaus = 0;
    int yritykset = 0;

    int oikeaLuku = rand() % maxnum + 1;

    std::cout << "Arvaa tietokoneen arpomaa lukua väliltä 1-" << maxnum << "!\n";

    while (arvaus != oikeaLuku) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> arvaus;

        yritykset++;

        if (arvaus < oikeaLuku) {
            std::cout << "Luku on suurempi.\n";
        } else if (arvaus > oikeaLuku) {
            std::cout << "Luku on pienempi.\n";
        } else {
            std::cout << "Oikea vastaus!\n";
        }
    }

    return yritykset;
}

int main() {

    srand(time(0));

    int maksimi = 20;

    int arvaustenMaara = game(maksimi);

    std::cout << "Arvasit oikein " << arvaustenMaara << " yrityksellä!\n";

    return 0;
}
