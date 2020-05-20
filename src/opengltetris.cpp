#include "opengltetris.h"

OpenGLTetris::OpenGLTetris(): Tetris()
{

}

bool OpenGLTetris::keystrokes() {
    return false;
}

void OpenGLTetris::nextStateExtra(double elapsedTime, bool keyHit) {
    if (elapsedTime >= m_stepTime) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    if (keyHit) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    // std::cout << deltaTime << '\n';
}
