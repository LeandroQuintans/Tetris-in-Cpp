#include <iostream>
#include <unistd.h>
#include <chrono>
#include <conio.h>

#include "matrix.h"
#include "piece.h"
#include "tetris.h"
#include "testtetris.h"


int main(int argc, char const *argv[]) {
    TestTetris t;

    t.gameloop();

    // while (true) {
    //     int i = getch();
    //     std::cout << i << '\n';
    // }

    // auto now(std::chrono::steady_clock::now());
    // auto seconds_since_epoch(
    //     std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()));

    // // Construct time_t using 'seconds_since_epoch' rather than 'now' since it is
    // // implementation-defined whether the value is rounded or truncated.
    // // std::time_t now_t(
    // //         std::chrono::system_clock::to_time_t(
    // //             std::chrono::system_clock::time_point(seconds_since_epoch)));

    // sleep(5);

    // auto delta = std::chrono::duration<double>(now.time_since_epoch() - seconds_since_epoch).count();

    // std::cout << delta << '\n';

    // std::time_t startTime = std::time(nullptr);
    // sleep(10);
    // std::time_t endTime = std::time(nullptr);

    // std::cout << std::difftime(endTime, startTime) << '\n';

    // std::cout << t.m_currentPiece << '\n';
    // t.nextPiece();
    // std::cout << t.m_currentPiece << '\n';
    // t.nextPiece();
    // std::cout << t.m_currentPiece << '\n';
    // t.nextPiece();
    // std::cout << t.m_currentPiece << '\n';
    // t.nextPiece();
    // std::cout << t.m_currentPiece << '\n';
    // t.nextPiece();
    // tetris::Piece pI{tetris::Piece::ShapeName::I_TETROMINO};
    // for (int i = 10; i < 19; ++i) {
    //     std::pair<std::size_t, std::size_t> newPosition{i, 0};
    //     t.placePieceInField(pI, newPosition);
    // }

    // std::cout << t.m_piecePosition.first << ' ' << t.m_piecePosition.second << '\n';


    // t.movePieceRight();
    // t.hardDropPiece();
    // std::cout << t.m_piecePosition.first << ' ' << t.m_piecePosition.second << '\n';

    // tetris::Piece pO{tetris::Piece::ShapeName::O_TETROMINO};

    // std::pair<std::size_t, std::size_t> newPosition{19, 0};
    // std::cout << t.m_currentPiece << '\n';
    // std::cout << t.m_piecePosition.first << ' ' << t.m_piecePosition.second  << '\n';
    // std::cout << newPosition.first << ' ' << newPosition.second  << '\n';

    // for (int i = 10; i < 19; i+=2) {
    //     std::pair<std::size_t, std::size_t> newPosition{i, 4};
    //     t.placePieceInField(pI, newPosition);
    // }
    // for (int i = 14; i < 19; i+=2) {
    //     std::pair<std::size_t, std::size_t> newPosition{i, 7};
    //     t.placePieceInField(pO, newPosition);
    // }

    // for (int i = 6; i < 10; ++i) {
    //     std::pair<std::size_t, std::size_t> newPosition{i, 6};
    //     t.placePieceInField(pI, newPosition);
    // }


    // std::cout << t.m_playfield << '\n';

    // t.clearLines();

    // std::cout << t.m_playfield << '\n';

    // std::pair<std::size_t, std::size_t> newPosition{11, 3};

    // std::cout << t.canPieceBePlaced(p, newPosition) << '\n';


    // for (int i = 0; i < 3; ++i) {
    //     std::cout << t.m_pieceBuffer.front() << '\n';
    //     t.m_pieceBuffer.pop();
    // }



    // mycontainers::Matrix<int, 3, 3> m{1, 2, 3, 
    //                                   4, 5, 6, 
    //                                   7, 8, 9};

    // std::cout << m << '\n';
    // auto mRow1 = m.atRow(1);
    // for (std::size_t i = 0; i < m.getWidth(); ++i)
    //     std::cout << mRow1[i] << ' ';
    // std::cout << '\n';
    // auto mCol1 = m.atCol(1);
    // for (std::size_t i = 0; i < m.getHeight(); ++i)
    //     std::cout << mCol1[i] << ' ';
    // std::cout << '\n';


    return 0;
}