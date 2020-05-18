namespace mycontainers {
    template<class T, std::size_t width, std::size_t height>
    std::size_t Matrix<T, width, height>::getWidth() {
        return width;
    }

    template<class T, std::size_t width, std::size_t height>
    std::size_t Matrix<T, width, height>::getHeight() {
        return height;
    }

    template<class T, std::size_t width, std::size_t height>
    T& Matrix<T, width, height>::at(std::size_t row, std::size_t col) {
        if (row >= height)
            throw std::out_of_range("row out of bounds");
        if (col >= width)
            throw std::out_of_range("col out of bounds");

        return m_matrix[row][col];
    }

    template<class T, std::size_t width, std::size_t height>
    const T& Matrix<T, width, height>::view(std::size_t row, std::size_t col) const {
        if (row >= height)
            throw std::out_of_range("row out of bounds");
        if (col >= width)
            throw std::out_of_range("col out of bounds");

        return m_matrix[row][col];
    }

}
