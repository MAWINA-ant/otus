#include <iostream>
#include <memory>
#include <assert.h>

#include "sparsematrix.h"

int main() {
    /*SparseMatrix<int, -1> matrix;
    assert(matrix.size() == 0); // все ячейки свободны
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
    std::cout << matrix[100][100] << "\n";
    ((matrix[200][200] = 314) = 0) = 217;
    // выведется одна строка
    // 100100314
    for(auto c: matrix)
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c.second;
        std::cout << x << y << v << std::endl;
    }*/

    SparseMatrix<int, 0> matrix;
    for (auto i = 0; i < 10; ++i) {
        for (auto j = 0; j < 10; ++j) {
            if (i == j) {
                matrix[i][j] = i;
            }
        }
    }
    for (auto i = 0; i < 10; ++i) {
        for (auto j = 9; j >= 0; --j) {
            if (i + j == 9) {
                matrix[i][j] = j;
            }
        }
    }
    for (auto i = 1; i < 9; ++i) {
        for (auto j = 1; j < 9; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "size of matrix = " <<  matrix.size() << "\n";
    for(auto c: matrix)
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c.second;
        std::cout << x << y << v << std::endl;
    }

    matrix[100][100] = 21;
    std::cout << matrix[100][100] << "\n";
    ((matrix[100][100] = 314) = 0) = 217;
    std::cout << matrix[100][100] << "\n";
    return 0;
}
