#ifndef OPENGLTETRIS_H
#define OPENGLTETRIS_H


#include <iostream>
#include "tetris.h"

class OpenGLTetris: public tetris::Tetris {
public:
    enum class Move {
        NO_MOVE,

        ROTATE_CLOCK,
        ROTATE_COUNTER_CLOCK,
        MOVE_LEFT,
        MOVE_RIGHT,
        ENABLE_SOFT_DROP,
        DISABLE_SOFT_DROP,
        HARD_DROP,

        MAX_MOVES
    };

    Move m_currentMove = Move::NO_MOVE;

    OpenGLTetris();
    virtual bool keystrokes() override final;
    virtual void nextStateExtra(double elapsedTime, bool keyHit) override final;
};

#endif