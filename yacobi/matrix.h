#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using std::vector;
using std::size_t;

template <class T>
vector<vector<T>> multiply_matrices(const vector<vector<T>> &a, const vector<vector<T>> &b)
{
    const size_t n = a.size(); // a rows
    const size_t m = a[0].size(); // a columns
    const size_t p = b[0].size(); // b columns

    vector<vector<T>> c(n, vector<T>(p, 0));
    for (size_t j = 0; j < p; ++j) {
        for (size_t k = 0; k < m; ++k) {
            for (size_t i = 0; i < n; ++i) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

template <class T>
vector<vector<T>> transpose_matrix(const vector<vector<T>> &a)
{
    const size_t n = a.size();     // a rows
    const size_t m = a[0].size();  // a cols

    vector<vector<T>> aT(m, vector<T>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            aT[i][j] = a[j][i];
        }
    }

    return aT;
}

template <class T>
vector<vector<T>> create_identity_matrix(size_t n, T)
{
    vector<vector<T>> identity_matrix(n, vector<T>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        identity_matrix[i][i] = 1;
    }

    return identity_matrix;
}

#endif // MATRIX_H
