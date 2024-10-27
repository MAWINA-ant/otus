#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <tuple>

struct Id
{
    int row;
    int column;

    bool operator==(const Id& other) const
    {
        return row == other.row && column == other.column;
    }

    struct HashFunction
    {
        size_t operator()(const Id& pos) const
        {
            size_t rowHash = std::hash<size_t>()(pos.row);
            size_t colHash = std::hash<size_t>()(pos.column) << 1;
            return rowHash ^ colHash;
        }
    };
};

template <typename T, T base>
struct SparseMatrix;

template <typename T, T base>
struct MatrixValue {
    int row;
    int column;
    T value;

    MatrixValue(int r, int c, T v, SparseMatrix<T, base>& m) : row{r}, column{c}, value{v}, matrix{m} {}

    operator std::tuple<int&, int&, T&>() { return {row, column, value}; }

    MatrixValue& operator=(const T& val) {
        if (matrix.hasElement(row, column)) {
            value = val;
            return *this;
        }
        this->value = val;
        matrix.insert(Id{row, column}, *this);
        return *this;
    }

    T& operator=(MatrixValue& val) {
        if (matrix.hasElement(val.row, val.column)) {
            return val.value;
        }
        return matrix.getDef();
    }

    bool operator==(const T& val) {
        return this->value == val;
    }

private:
    SparseMatrix<T, base>& matrix;
};


template <typename T, T base>
std::ostream& operator<<(std::ostream& os, const MatrixValue<T,base>& val) {
    return os << val.value;
}

template <typename T, T base>
struct RowMatrix {
    RowMatrix(size_t r, SparseMatrix<T, base>* m) : row{r}, matrix{m} {}
    MatrixValue<T, base> operator [](size_t idx) {
        return matrix->get(row, idx);
    }
private:
    size_t row;
    SparseMatrix<T, base>* matrix;
};

template <typename T, T base>
struct SparseMatrix {
    size_t size() {
        return data.size();
    }

    RowMatrix<T,base> operator [](size_t idx) {
        return {idx, this};
    }

    MatrixValue<T, base> get(int row, int column) {
        auto it = data.find(Id{row, column});
        if (it == data.end()) {
            return {row, column, def, *this};
        }
        return it->second;
    }

    bool hasElement(int row, int column) {
        auto it = data.find(Id{row, column});
        return it != data.end();
    }

    void insert(Id id, MatrixValue<T, base> val) {
        data.insert(std::make_pair(id, val));
    }

    void changeElement(Id id, MatrixValue<T, base> val) {
        data[id] = val;
    }

    T& getDef() { return def; }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
private:
    T def = base;
    std::unordered_map<Id, MatrixValue<T, base>, Id::HashFunction> data;
};

#endif // SPARSEMATRIX_H
