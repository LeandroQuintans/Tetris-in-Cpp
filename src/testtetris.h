#ifndef TESTTETRIS_H
#define TESTTETRIS_H

#include <conio.h>
#include <iostream>

#include "tetris.h"


class TestTetris: public tetris::Tetris {
public:
    TestTetris();

    virtual void extraGameloop(double deltaTime) override final;
};

#endif
