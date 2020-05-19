#include "tetris.h"

namespace tetris {

    Tetris::Tetris(): m_playfield{}, m_pieceBuffer{} {
        m_currentPiece = Piece::getRandomPiece();
        for (int i = 0; i < 3; ++i)
            m_pieceBuffer.push(Piece::getRandomPiece());
    }

    bool Tetris::canPieceBePlaced(const Piece& piece, const Coords2D& position) const {
        std::size_t pieceFormHeight = piece.currentFormation().getHeight();
        std::size_t pieceFormWidth = piece.currentFormation().getWidth();

        for (std::size_t i = 0; i < pieceFormHeight; ++i) {
            for (std::size_t j = 0; j < pieceFormWidth; ++j) {
                if (piece.currentFormation().view(i, j)) {
                    if (i + position.first >= m_playfield.getHeight() 
                     || j + position.second >= m_playfield.getWidth()) {
                        return false;
                    }
                    else if (m_playfield.view(i + position.first, j + position.second)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    void Tetris::placePieceInField(const Piece& piece, const Coords2D& position) {
        std::size_t pieceFormHeight = piece.currentFormation().getHeight();
        std::size_t pieceFormWidth = piece.currentFormation().getWidth();

        for (std::size_t i = 0; i < pieceFormHeight; ++i) {
            for (std::size_t j = 0; j < pieceFormWidth; ++j) {
                if (piece.currentFormation().view(i, j)) {
                    m_playfield.at(i + position.first, j + position.second) 
                        = piece.currentFormation().view(i, j);
                }
            }
        }
    }

    void Tetris::nextPiece() {
        m_currentPiece = m_pieceBuffer.front();
        m_pieceBuffer.pop();
        m_pieceBuffer.push(Piece::getRandomPiece());
    }

    bool Tetris::movePiece(int vrtclDirection, int hrzntlDirection) {
        if (canPieceBePlaced(m_currentPiece, Coords2D{
                                                m_piecePosition.first+vrtclDirection,
                                                m_piecePosition.second+hrzntlDirection
                                            })) {
            m_piecePosition.first += vrtclDirection;
            m_piecePosition.second += hrzntlDirection;
            return true;
        }
        return false;
    }

    void Tetris::clearLines() {
        bool clear = true;
        for (std::size_t i = m_piecePosition.first; i < m_playfield.getHeight(); ++i) {
            for (std::size_t j = 0; j < m_playfield.getWidth(); ++j) {
                if (!m_playfield.view(i, j)) {
                    clear = false;
                    ++m_linesCleared;
                    break;
                }
            }
            if (clear) {
                for (std::size_t i2 = i; i2 > 0; --i2) {
                    for (std::size_t j2 = 0; j2 < m_playfield.getWidth(); ++j2) {
                        m_playfield.at(i2, j2) = m_playfield.at(i2-1, j2);
                    }
                }
            }
            clear = true;
        }
    }

    bool Tetris::movePieceLeft() {
        return movePiece(0, -1);
    }

    bool Tetris::movePieceRight() {
        return movePiece(0, 1);
    }

    bool Tetris::movePieceDown() {
        return movePiece(1, 0);
    }

    void Tetris::rotatePieceClockwise() {
        do {
            m_currentPiece.rotatePieceClockwise();
        } while (!canPieceBePlaced(m_currentPiece, m_piecePosition));
    }

    void Tetris::rotatePieceCounterClockwise() {
        do {
            m_currentPiece.rotatePieceCounterClockwise();
        } while (!canPieceBePlaced(m_currentPiece, m_piecePosition));
    }

    void Tetris::softDropPiece() {

    }

    void Tetris::hardDropPiece() {

    }

    void Tetris::level() {
        return m_linesCleared % 10 + 1 > 20 ? 20 : m_linesCleared % 10 + 1;
    }

}