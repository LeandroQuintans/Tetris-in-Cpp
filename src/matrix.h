#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

namespace mycontainers {
    // Aggregate class for a matrix of T objects
    template<class T, std::size_t width, std::size_t height>
    class Matrix {
    public:
        // Support height = 0 and width = 0
        T m_matrix[height ? height : 1][width ? width : 1];

        // Returns reference to element at row and col
        T& at(std::size_t row, std::size_t col);
    };

}

#include "matrix.inl"

#endif