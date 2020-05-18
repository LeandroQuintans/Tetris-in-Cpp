#ifndef MATRIX_H
#define MATRIX_H

// #include <array>
#include <stdexcept>
#include <iostream>

namespace mycontainers {

    // Aggregate class for a matrix of T objects
    template<class T, std::size_t width, std::size_t height>
    class Matrix {
    public:
        // Support height = 0 and width = 0
        T m_matrix[height ? height : 1][width ? width : 1];

        std::size_t getWidth() const;
        std::size_t getHeight() const;

        // Returns reference to element at row and col
        T& at(const std::size_t row, const std::size_t col);

        // Returns const reference to element at row and col
        const T& view(const std::size_t row, std::size_t col) const;

        // Returns an array with indexes for the requested row
        // std::array<std::size_t, width> atRow(std::size_t row) const;
        // Returns an array with indexes for the requested col
        // std::array<std::size_t, height> atCol(std::size_t col) const;

        friend std::ostream& operator<<(std::ostream &out, const Matrix<T, width, height> &matrix) {
            for (std::size_t i = 0; i < height; ++i) {
                for (std::size_t j = 0; j < width; ++j)
                    out << matrix.m_matrix[i][j] << ' ';
                out << '\n';
            }
            return out;
        }

    };

}

#include "matrix.inl"

#endif