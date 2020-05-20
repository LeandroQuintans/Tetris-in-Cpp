#include "opengltetris.h"

OpenGLTetris::OpenGLTetris(): Tetris()
{

}

bool OpenGLTetris::keystrokes() {
    return false;
}

void OpenGLTetris::extraGameloop(double deltaTime, bool keyHit) {
    if (deltaTime >= m_stepTime) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    if (keyHit) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }

}