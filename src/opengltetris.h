#ifndef OPENGLTETRIS_H
#define OPENGLTETRIS_H


#include <iostream>
#include "tetris.h"

class OpenGLTetris: public tetris::Tetris {
public:
    OpenGLTetris();
    virtual bool keystrokes() override final;
    virtual void nextStateExtra(double elapsedTime, bool keyHit) override final;
};

#endif