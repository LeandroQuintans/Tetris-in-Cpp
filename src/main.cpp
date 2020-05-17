#include <iostream>

#include "matrix.h"
#include "tetris.h"


int main(int argc, char const *argv[]) {
    tetris::Piece p{tetris::ShapeName::I_TETROMINO};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << p.currentFormation().at(i, j);
        }
        std::cout << '\n';
    }

    std::cout << '\n' << static_cast<int>(p.getShapeName()) << '\n';

    p.rotateCounterClockwise();

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << p.currentFormation().at(i, j);
        }
        std::cout << '\n';
    }

    std::cout << '\n' << static_cast<int>(p.getShapeName()) << '\n';

    p.rotateCounterClockwise();

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << p.currentFormation().at(i, j);
        }
        std::cout << '\n';
    }

    std::cout << '\n' << static_cast<int>(p.getShapeName()) << '\n';

    p.rotateCounterClockwise();

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << p.currentFormation().at(i, j);
        }
        std::cout << '\n';
    }

    std::cout << '\n' << static_cast<int>(p.getShapeName()) << '\n';

    p.rotateCounterClockwise();

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << p.currentFormation().at(i, j);
        }
        std::cout << '\n';
    }

    std::cout << '\n' << static_cast<int>(p.getShapeName()) << '\n';

    return 0;
}