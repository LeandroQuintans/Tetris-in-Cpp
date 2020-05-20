#ifndef TETRIS_H
#define TETRIS_H

#include <queue>
#include <utility>
#include <iostream>
#include <cmath>
#include <chrono>

#include "matrix.h"
#include "piece.h"

namespace tetris {

    class Tetris {
    public:
        typedef mycontainers::Matrix<int, 10, 20> Playfield;
        typedef std::pair<int, int> Coords2D;

    protected:
        Playfield m_playfield;
        int m_linesCleared = 0;
        std::queue<Piece> m_pieceBuffer;
        Piece m_currentPiece;

        // m_piecePosition is a pair of row and col indexes that point to where the
        // first element of the m_currentPiece formation should be translated to in the
        // m_playfield
        Coords2D m_piecePosition{0, 3};

        // time in seconds
        double m_stepTime = 1.0;

        bool canPieceBePlaced(const Piece& piece, const Coords2D& position) const;

        // Assumes piece can be placed
        virtual void placePieceInField(const Piece& piece, const Coords2D& position);

        void nextPiece();
        virtual bool movePiece(int vrtclDirection, int hrzntlDirection);
        virtual void clearLines();

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

        Playfield currentPlayfield() const;
        int level();
        void updateStepTime();

        virtual bool keystrokes() = 0;
        virtual void nextStateExtra(double elapsedTime, bool keyHit);
        virtual bool nextState(double elapsedTime, std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long int, std::ratio<1, 1000000000>>>& startTime);
        void gameloop();

        friend std::ostream& operator<<(std::ostream &out, const Tetris &tetris);
    };
}

#endif