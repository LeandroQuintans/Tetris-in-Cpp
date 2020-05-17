#include <cassert>

#include "matrix.h"


void testListInitializer() {
    mycontainers::Matrix<int, 4, 4> m{0,  1,  2,  3, 
                                      4,  5,  6,  7, 
                                      8,  9,  10, 11,
                                      12, 13, 14, 15};

    int count = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            assert(m.at(i, j) == count);
            count++;
        }
}


int main(int argc, char const *argv[])
{
    testListInitializer();
    return 0;
}