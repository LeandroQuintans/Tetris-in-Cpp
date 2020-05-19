#ifndef TETRIS_H
#define TETRIS_H

#include <queue>
#include <utility>
#include <iostream>
#include <cmath>
#include <ctime>

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

        double m_stepTime = 1.0;

        bool canPieceBePlaced(const Piece& piece, const Coords2D& position) const;

        // Assumes piece can be placed
        void placePieceInField(const Piece& piece, const Coords2D& position);

        void nextPiece();
        bool movePiece(int vrtclDirection, int hrzntlDirection);
        void clearLines();

    public:
        Tetris();

        bool movePieceLeft();
        bool movePieceRight();
        bool movePieceDown();
        void rotatePieceClockwise();
        void rotatePieceCounterClockwise();
        void enableSoftDropPiece();
        void disableSoftDropPiece();
        void hardDropPiece();

        int level();

        // time in seconds
        double stepTime();

        void gameLoop();

        friend std::ostream& operator<<(std::ostream &out, const Tetris &tetris);
    };
}

#endif