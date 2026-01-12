#include <iostream>
#include <cstdlib>
#include <ctime>

//Älä käytä QT!!! Kone kaatuuu!!!

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    int oikealuku = std::rand() % 20 + 1;
    int arvaus = 0;

    std::cout << "Arvaa tietokoneen arpoma luku väliltä 1-20. \n";

    while (arvaus != oikealuku) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> arvaus;

        if (arvaus < oikealuku) {
            std::cout << "Luku on suurempi. \n";
        } else if (arvaus > oikealuku) {
            std::cout << "Luku on pienempi. \n";
        } else {
            std::cout << "Oikea vastaus!\n";
        }
    }
    return 0;
}
