#include "testtetris.h"


TestTetris::TestTetris(): Tetris() {
}

void TestTetris::extraGameloop(double deltaTime) {
    if (deltaTime >= m_stepTime) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    // std::cout << deltaTime << '\n';
}

