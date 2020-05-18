#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <ctime>
#include <random>
#include <iostream>

#include "matrix.h"

namespace tetris {

    enum class RotationDeg {
        DEGREE_0,
        DEGREE_90,
        DEGREE_180,
        DEGREE_270,

        MAX_ROTATIONS
    };

    enum class ShapeName {
        MIN_SHAPES,

        I_TETROMINO,
        O_TETROMINO,
        T_TETROMINO,
        S_TETROMINO,
        Z_TETROMINO,
        J_TETROMINO,
        L_TETROMINO,

        MAX_SHAPES
    };

    class Piece {
    public:
        typedef mycontainers::Matrix<int, 4, 4> PieceShape;
        typedef std::array<PieceShape, static_cast<std::size_t>(RotationDeg::MAX_ROTATIONS)> Formations;

    private:
        Formations m_formations;
        ShapeName m_shapeName;
        RotationDeg m_currentRotation = RotationDeg::DEGREE_0;
        
        // Changes m_currentRotation to the aproppriate one depending on the argument direction
        // negative direction goes backwards in the m_formations array, positive goes forward
        // loops around the m_formations array
        void rotate(int direction);
        
    public:
        Piece();
        Piece(ShapeName shapeName);

        // Chooses a random ShapeName
        static Piece getRandomPiece();

        void rotateClockwise();
        void rotateCounterClockwise();
        const PieceShape& currentFormation() const;
        ShapeName getShapeName();

        friend std::ostream& operator<<(std::ostream &out, const Piece &piece);
    };
}

#endif