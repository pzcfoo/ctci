#include <iostream>
#include <stdexcept>
#include <vector>
#include "c1_6.h"
#include "utils.h"


namespace c1_6
{
    void rotate_matrix(std::vector<char> &matrix, int N)
    {
        int max_layer = N / 2;
        int n = N - 1;
        for (int l = 0; l < max_layer; l++)
        {
            for (int i = 0 + l; i < (n - l); i++)
            {
                // debug
                int ix_a = utils::_index(l, i, N);
                int ix_b = utils::_index(n - i, l, N);
                int ix_c = utils::_index(n - l, n - i, N);
                int ix_d = utils::_index(i, n - l, N);

                char t = matrix[ix_b];
                matrix[ix_b] = matrix[ix_a];
                std::swap(matrix[ix_c], t);
                std::swap(matrix[ix_d], t);
                std::swap(matrix[ix_a], t);
            }
        }
    }

    void run_c1_6()
    {
        std::vector<char> matrix = {
            'a', 'b', 'c',
            'd', 'e', 'f',
            'g', 'h', 'i'
        };

        std::vector<char> matrix_4 = {
            'a', 'b', 'c', 'd',
            'e', 'f', 'g', 'h',
            'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p'
        };

        std::vector<char> matrix_5 = {
            'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o',
            'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y'
        };

        int n = 3;
        int n_4 = 4;
        int n_5 = 5;

        if (
            !utils::matrix_is_square(matrix, n)
            or !utils::matrix_is_square(matrix_4, n_4)
            or !utils::matrix_is_square(matrix_5, n_5)
        )
        {
            throw std::exception();
        }

        utils::print_matrix<char>(matrix, n);
        rotate_matrix(matrix, n);
        utils::print_matrix<char>(matrix, n);

        utils::print_matrix<char>(matrix_4, n_4);
        rotate_matrix(matrix_4, n_4);
        utils::print_matrix<char>(matrix_4, n_4);

        utils::print_matrix<char>(matrix_5, n_5);
        rotate_matrix(matrix_5, n_5);
        utils::print_matrix<char>(matrix_5, n_5);
    }
}
