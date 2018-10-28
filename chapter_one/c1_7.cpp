#include <iostream>
#include "c1_7.h"
#include "utils.h"


namespace c1_7
{
    void _zerofy_row(std::vector<int> &matrix, int target_row, int m, int n)
    {
        for (int k = 0; k < n; k++)
        {
            int ix = utils::_index(target_row, k, m, n);
            matrix[ix] = 0;
        }
    }

    void _zerofy_col(std::vector<int> &matrix, int target_col, int m, int n)
    {
        for (int k = 0; k < m; k++)
        {
            int ix = utils::_index(k, target_col, m, n);
            matrix[ix] = 0;
        }
    }

    void zerofy_matrix(std::vector<int> &matrix, int m, int n)
    {
        std::vector<std::pair<int, int>> coord_to_zerofy = {};
        for (int i = 0; i < m; i++) // rows
        {
            for (int j = 0; j < n; j++) // cols
            {
                int ix_a = utils::_index(i, j, m, n);
                if (matrix[ix_a] == 0)
                {
                    coord_to_zerofy.push_back({i, j});
                }
            }
        }
        for (auto coord: coord_to_zerofy)
        {
            int r = coord.first;
            int c = coord.second;
            _zerofy_row(matrix, r, m, n);
            _zerofy_col(matrix, c, m, n);
        }
    }

    void run_c1_7()
    {
        std::vector<int> matrix = {
            0, 1, 1, 1,
            1, 1, 1, 1,
            1, 0, 1, 1,
        };
        std::vector<int> matrix_a = {
            1, 1, 1, 0,
            1, 1, 1, 1,
            0, 1, 1, 1,
        };


        int m = 3;
        int n = 4;

        utils::print_matrix<int>(matrix, n);
        zerofy_matrix(matrix, m, n);
        utils::print_matrix<int>(matrix, n);

        utils::print_matrix<int>(matrix_a, n);
        zerofy_matrix(matrix_a, m, n);
        utils::print_matrix<int>(matrix_a, n);
    }
}
