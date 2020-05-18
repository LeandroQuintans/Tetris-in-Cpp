namespace mycontainers {
    template<class T, std::size_t width, std::size_t height>
    std::size_t Matrix<T, width, height>::getWidth() const {
        return width;
    }

    template<class T, std::size_t width, std::size_t height>
    std::size_t Matrix<T, width, height>::getHeight() const {
        return height;
    }

    template<class T, std::size_t width, std::size_t height>
    T& Matrix<T, width, height>::at(const std::size_t row, const std::size_t col) {
        if (row >= height)
            throw std::out_of_range("row out of bounds");
        if (col >= width)
            throw std::out_of_range("col out of bounds");

        return m_matrix[row][col];
    }

    template<class T, std::size_t width, std::size_t height>
    const T& Matrix<T, width, height>::view(const std::size_t row, const std::size_t col) const {
        if (row >= height)
            throw std::out_of_range("row out of bounds");
        if (col >= width)
            throw std::out_of_range("col out of bounds");

        return m_matrix[row][col];
    }

    // template<class T, std::size_t width, std::size_t height>
    // std::array<T, width> Matrix<T, width, height>::atRow(std::size_t row) const {
    //     std::array<std::size_t, width> result{};
    //     for (std::size_t j = 0; j < width; ++j)
    //         result[j] = m_matrix[row][j];

    //     return result;
    // }

    // template<class T, std::size_t width, std::size_t height>
    // std::array<std::size_t, height> Matrix<T, width, height>::atCol(std::size_t col) const {
    //     std::array<std::size_t, height> result{};
    //     for (std::size_t i = 0; i < height; ++i)
    //         result[i] = m_matrix[i][col];

    //     return result;
    // }

}
