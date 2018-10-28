#include <iostream>
#include <vector>


namespace utils
{
    bool matrix_is_square(std::vector<char> matrix, int n);

    template <typename T>
    void print_matrix(std::vector<T> matrix, int columns)
    {
        for (auto i = 0; i < matrix.size(); i++)
        {
            if ((i % columns == 0) && (i != 0))
            {
                std::cout << std::endl;
            }
            std::cout << matrix[i] << ' ';
        }
        std::cout << std::endl << std::endl;
    }

    int _index(int r, int c, int N);

    int _index(int r, int c, int M, int N);
}
