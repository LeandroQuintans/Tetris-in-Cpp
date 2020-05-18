#ifndef TETRIS_H
#define TETRIS_H

#include <queue>
#include <iostream>

#include "matrix.h"
#include "piece.h"

namespace tetris {

    class Tetris {
    public:
        typedef mycontainers::Matrix<int, 10, 20> Playfield;

    public:
        Playfield m_playfield;
        int m_linesCleared = 0;
        std::queue<Piece> m_pieceBuffer;
        Piece m_currentPiece;

        movePiece(int direction);

    public:
        Tetris();

        movePieceLeft();
        movePieceRight();
        rotatePieceClockwise();
        rotatePieceCounterClockwise();
        softDropPiece();
        hardDropPiece();
        clearLines();

        gameLoop();
    };
}

#endif