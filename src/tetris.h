#ifndef TETRIS_H
#define TETRIS_H

#include <queue>
#include <utility>
#include <iostream>

#include "matrix.h"
#include "piece.h"

namespace tetris {

    class Tetris {
    public:
        typedef mycontainers::Matrix<int, 10, 20> Playfield;
        typedef std::pair<std::size_t, std::size_t> Coords2D;

    public:
        Playfield m_playfield;
        int m_linesCleared = 0;
        std::queue<Piece> m_pieceBuffer;
        Piece m_currentPiece;

        // m_piecePosition is a pair of row and col indexes that point to where the
        // first element of the m_currentPiece formation should be translated to in the
        // m_playfield
        Coords2D m_piecePosition{0, 3};

        bool canPieceBePlaced(const Piece& piece, const Coords2D& position) const;
        void movePiece(int hrzntlDirection, int vrtclDirection);
        void placePieceInField();

    public:
        Tetris();

        void movePieceLeft();
        void movePieceRight();
        void movePieceDown();
        void rotatePieceClockwise();
        void rotatePieceCounterClockwise();
        void softDropPiece();
        void hardDropPiece();
        void clearLines();

        void gameLoop();
    };
}

#endif