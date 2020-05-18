#include "tetris.h"

namespace tetris {

    Tetris::Tetris(): m_playfield{}, m_pieceBuffer{} {
        for (int i = 0; i < 3; ++i)
            m_pieceBuffer.push(Piece::getRandomPiece());
        m_currentPiece = Piece::getRandomPiece();
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
}