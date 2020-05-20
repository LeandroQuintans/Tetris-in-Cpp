#include "testtetris.h"


TestTetris::TestTetris(): Tetris() {
}

bool TestTetris::keystrokes() {
    if (kbhit()) {
        int key = getch();
        if (key == 105) {
            rotatePieceClockwise();
        }
        else if (key == 106) {
            movePieceLeft();
        }
        else if (key == 107) {
            enableSoftDropPiece();
        }
        // else if (key ==) {
            
        // }
        else if(key == 108) {
            movePieceRight();
        }
        else if(key == 122) {
            rotatePieceCounterClockwise();
        }
        else if(key == 32) {
            hardDropPiece();
            placePieceInField(m_currentPiece, m_piecePosition);
            clearLines();
            nextPiece();
        }
        return true;
    }
    return false;
}

void TestTetris::extraGameloop(double deltaTime, bool keyHit) {
    if (deltaTime >= m_stepTime) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    if (keyHit) {
        std::cout << Tetris::currentPlayfield() << '\n';
    }
    // std::cout << deltaTime << '\n';
}

