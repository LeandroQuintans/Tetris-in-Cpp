#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

namespace mycontainers {

    // Aggregate class for a matrix of T objects
    template<class T, std::size_t width, std::size_t height>
    class Matrix {
    public:
        // Support height = 0 and width = 0
        T m_matrix[height ? height : 1][width ? width : 1];

        // Returns reference to element at row and col
        T& at(std::size_t row, std::size_t col);

    private:
        // Returns constant reference to element at row and col (used for operator<<)
        const T& view(std::size_t row, std::size_t col) const;

    public:
        friend std::ostream& operator<<(std::ostream &out, const Matrix<T, width, height> &matrix) {
            for (std::size_t i = 0; i < height; ++i) {
                for (std::size_t j = 0; j < width; ++j)
                    out << matrix.view(i, j) << ' ';
                out << '\n';
            }
            return out;
        }

    };

}

#include "matrix.inl"

#endif