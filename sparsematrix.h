#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <vector>
#include <tuple>

template<typename T, int defValue = -1>
class SparseMatrix
{
public:
    SparseMatrix();
    unsigned int occupiedCellsCount();
    void showElements();
    SparseMatrix& operator=();
    SparseMatrix* operator[]();

private:
    std::vector<std::tuple<unsigned, unsigned, T>> values;
};

class ProxySparseMatrix {
public:
    ProxySparseMatrix(SparseMatrix* m);

private:
    SparseMatrix *matrix;
};

#endif // SPARSEMATRIX_H
