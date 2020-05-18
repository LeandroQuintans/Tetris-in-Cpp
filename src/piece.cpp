#include "tetris.h"

namespace tetris {
    void Piece::rotate(int direction) {
        int intCurrentRotation = static_cast<int>(m_currentRotation);
        intCurrentRotation += direction;

        int maxRotations = static_cast<int>(RotationDeg::MAX_ROTATIONS);
        if (intCurrentRotation < 0)
            intCurrentRotation += maxRotations;
        else if (intCurrentRotation >= maxRotations)
            intCurrentRotation -= maxRotations;

        m_currentRotation = static_cast<RotationDeg>(intCurrentRotation);
    }


    Piece::Piece(): m_formations{}, m_shapeName{ShapeName::MIN_SHAPES} {
    }

    Piece::Piece(ShapeName shapeName) {
        int intShapeName = static_cast<int>(shapeName);

        switch (shapeName) {
            case ShapeName::I_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{0, 0, 0, 0, 
                                                 intShapeName, intShapeName, intShapeName, intShapeName, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{0, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   0, 0, 0, 0, 
                                                   intShapeName, intShapeName, intShapeName, intShapeName, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, 0, intShapeName, 0, 
                                                   0, 0, intShapeName, 0, 
                                                   0, 0, intShapeName, 0, 
                                                   0, 0, intShapeName, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::O_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{0, intShapeName, intShapeName, 0, 
                                                 0, intShapeName, intShapeName, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{0, intShapeName, intShapeName, 0, 
                                                  0, intShapeName, intShapeName, 0, 
                                                  0, 0, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, 0, 0, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, 0, 0, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::T_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{0, intShapeName, 0, 0, 
                                                 intShapeName, intShapeName, intShapeName, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{0, intShapeName, 0, 0, 
                                                  intShapeName, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   intShapeName, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, intShapeName, 0, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::S_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{0, intShapeName, intShapeName, 0, 
                                                 intShapeName, intShapeName, 0, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{intShapeName, 0, 0, 0, 
                                                  intShapeName, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   intShapeName, intShapeName, 0, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, intShapeName, 0, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, 0, intShapeName, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::Z_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{intShapeName, intShapeName, 0, 0, 
                                                 0, intShapeName, intShapeName, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{0, intShapeName, 0, 0, 
                                                  intShapeName, intShapeName, 0, 0, 
                                                  intShapeName, 0, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   intShapeName, intShapeName, 0, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, 0, intShapeName, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::J_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{intShapeName, 0, 0, 0, 
                                                 intShapeName, intShapeName, intShapeName, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{0, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  intShapeName, intShapeName, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   intShapeName, intShapeName, intShapeName, 0, 
                                                   0, 0, intShapeName, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, intShapeName, intShapeName, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            case ShapeName::L_TETROMINO: {
                Piece::PieceShape pieceShapeDeg0{0, 0, intShapeName, 0, 
                                                 intShapeName, intShapeName, intShapeName, 0, 
                                                 0, 0, 0, 0, 
                                                 0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg90{intShapeName, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, intShapeName, 0, 0, 
                                                  0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg180{0, 0, 0, 0, 
                                                   intShapeName, intShapeName, intShapeName, 0, 
                                                   intShapeName, 0, 0, 0, 
                                                   0, 0, 0, 0};
                Piece::PieceShape pieceShapeDeg270{0, intShapeName, 0, 0, 
                                                   0, intShapeName, 0, 0, 
                                                   0, intShapeName, intShapeName, 0, 
                                                   0, 0, 0, 0};
                m_formations = {pieceShapeDeg0, pieceShapeDeg90, pieceShapeDeg180, pieceShapeDeg270};
                break;
            }

            default: { //TODO throw exception here
                break;
            }
        }

        m_shapeName = shapeName;
    }

    Piece Piece::getRandomPiece() {
        static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::uniform_int_distribution die {static_cast<int>(ShapeName::MIN_SHAPES)+1, 
                                           static_cast<int>(ShapeName::MAX_SHAPES)-1};
        return Piece(static_cast<ShapeName>(die(mersenne)));
    }

    void Piece::rotateClockwise() {
        rotate(-1);
    }

    void Piece::rotateCounterClockwise() {
        rotate(1);
    }

    const Piece::PieceShape& Piece::currentFormation() const {
        return m_formations.at(static_cast<int>(m_currentRotation));
    }

    Piece::ShapeName Piece::getShapeName() {
        return m_shapeName;
    }

    std::ostream& operator<< (std::ostream &out, const Piece &piece) {
        out << piece.currentFormation();

        return out;
    }

}