#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxnum;
    int rnum;
    int count;

public:
    Game(int maxnum);
    void play();
    void printGameResult();
};

#endif