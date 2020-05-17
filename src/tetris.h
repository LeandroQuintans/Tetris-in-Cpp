#ifndef TETRIS_H
#define TETRIS_H

#include <array>
#include <ctime>
#include <random>

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
        I_TETROMINO,
        O_TETROMINO,
        T_TETROMINO,
        S_TETROMINO,
        Z_TETROMINO,
        J_TETROMINO,
        L_TETROMINO,

        MAX_SHAPES
    };

    // struct PieceShape {
    //     ShapeName m_shapeName;
    //     std::array<mycontainers::Matrix<int, 4, 4>, 4> m_structures;

    //     PieceShape(ShapeName shapeName);
    // };

    class Piece {
        typedef mycontainers::Matrix<int, 4, 4> PieceShape;
        typedef std::array<PieceShape, RotationDeg::MAX_ROTATIONS> Formations

    private:
        Formations m_formations;
        ShapeName m_shapeName;
        RotationDeg m_currentRotation = RotationDeg::DEGREE_0;
        
        Piece(ShapeName shapeName, Formations formations);

        void rotate(int direction);
    public:
        Piece(ShapeName shapeName);

        static Piece getRandomPiece();

        void rotateClockwise();
        void rotateCounterClockwise();
        PieceShape currentStructure();
    };

}

#endif