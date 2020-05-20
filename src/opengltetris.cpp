#include "opengltetris.h"

OpenGLTetris::OpenGLTetris(): Tetris()
{

}

bool OpenGLTetris::keystrokes() {
    if (m_currentMove > Move::NO_MOVE && m_currentMove < Move::MAX_MOVES) {
        if (m_currentMove == Move::ROTATE_CLOCK) {
            rotatePieceClockwise();
        }
        else if (m_currentMove == Move::ROTATE_COUNTER_CLOCK) {
            rotatePieceCounterClockwise();
        }
        else if (m_currentMove == Move::MOVE_LEFT) {
            movePieceLeft();
        }
        else if (m_currentMove == Move::MOVE_RIGHT) {
            movePieceRight();
        }
        else if (m_currentMove == Move::ENABLE_SOFT_DROP) {
            enableSoftDropPiece();
        }
        else if (m_currentMove == Move::DISABLE_SOFT_DROP) {
            disableSoftDropPiece();
        }
        else if (m_currentMove == Move::HARD_DROP) {
            hardDropPiece();
        }
        return true;
    }
    return false;
}

void OpenGLTetris::nextStateExtra(double elapsedTime, bool keyHit) {
    if (elapsedTime >= m_stepTimeUsed) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    if (keyHit) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    // std::cout << deltaTime << '\n';
}
