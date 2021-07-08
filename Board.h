#ifndef Board_H_
#define Board_H

#include<vector>
#include"Plate.h"
#include"Pole.h"

class Board {
public:
    int step;
    Pole* A;
    Pole* B;
    Pole* C;

    Board(int x);
    void help();
    int move(char from, char to);

    void show1(int x);
    void show2(int h);
    void init_2(int x);
};

#endif /*Board_H_*/"# hanoi" 
