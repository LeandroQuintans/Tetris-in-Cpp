#ifndef TESTTETRIS_H
#define TESTTETRIS_H

#include <conio.h>
#include <iostream>

#include "tetris.h"


class TestTetris: public tetris::Tetris {
public:
    TestTetris();

    virtual bool keystrokes() override final;
    virtual void nextStateExtra(double elapsedTime, bool keyHit) override final;
};

#endif
