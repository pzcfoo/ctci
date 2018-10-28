#include <iostream>
#include <exception>
#include <vector>
#include "utils.h"


namespace utils
{
    bool matrix_is_square(std::vector<char> matrix, int n)
    {
        return (n*n) == matrix.size();
    }

    int _index(int r, int c, int N)
    {
        // for square matrices
        if (r >= N)
        {
            // outside matrix dimensions
            throw std::exception();
        }
        return (r * N) + c;
    }

    int _index(int r, int c, int M, int N)
    {
        // for M by N matrices
        // M: num of rows
        // N: num of columns
        if ((r >= M) || (c >= N))
        {
            // outside matrix dimensions
            throw std::exception();
        }
        return (r * N) + c;
    }
}
