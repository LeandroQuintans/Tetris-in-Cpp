#include "tetris.h"

namespace tetris {

    Tetris::Tetris(): m_playfield{}, m_pieceBuffer{} {
        for (int i = 0; i < 3; ++i)
            m_pieceBuffer.push(Piece::getRandomPiece());
        m_currentPiece = Piece::getRandomPiece();
    }
}