#include "jacobi.h"
#include "matrix.h"

#include <limits>
#include <algorithm>

using namespace std;

int JacobiEigenvectors::jacobi(const vector<vector<double>> &matr, vector<double> &numbers, vector<vector<double>> &vectors)
{
    // copy the matrix to work with it
    vector<vector<double>> A = matr;

    // specify the precision
    double e = 0.0001;

    // indexes of all overdiagonal elements
    vector<pair<size_t, size_t>> indexes = find_indexes_of_over_diagonal_matrix_elements(A.size());
    size_t curr_overdiagonal_index = 0;
    vector<vector<double>> rotate_matrix_history = create_identity_matrix(A.size(), 1.);
    double max;
    do {
        // if the maximum element in the over diagonal matrix is less or equal than 'e' then calc own numbers
        max = find_max_in_over_diagonal_matrix(A);

        // otherwise the process continues
        pair<double, double> sincos = calc_rotation_sin_cos(A, indexes[curr_overdiagonal_index].first, indexes[curr_overdiagonal_index].second);

        // calculate the rotate matrix
        vector<vector<double>> rotate_matrix = calc_rotate_matrix(sincos.first, sincos.second, indexes[curr_overdiagonal_index].first, indexes[curr_overdiagonal_index].second, A.size());

        // calculate new A matrix
        vector<vector<double>> new_A = A;
        new_A = multiply_matrices(transpose_matrix(rotate_matrix), A);
        new_A = multiply_matrices(new_A, rotate_matrix);
        A = new_A;

        rotate_matrix_history = multiply_matrices(rotate_matrix_history, rotate_matrix);

        curr_overdiagonal_index = (curr_overdiagonal_index < indexes.size() - 1) ? curr_overdiagonal_index + 1 : 0;
    } while (max > e);

    for (size_t i = 0; i < A.size(); ++i) {
        numbers.push_back(A[i][i]);
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        vector<double> vec;
        for (size_t j = 0; j < numbers.size(); j++) {
            vec.push_back(rotate_matrix_history[j][i]);
        }

        vectors.push_back(vec);
    }

    return 0;
}

pair<double, double> JacobiEigenvectors::calc_rotation_sin_cos(const vector<vector<double>> &matr, size_t i, size_t j)
{
    double P = (2 * matr[i][j]) / (matr[i][i] - matr[j][j]);

    int signP = P > 0 ? 1 : -1;

    double sinf = signP * std::sqrt(0.5 * (1 - (1 / (sqrt(1 + P * P)))));
    double cosf = std::sqrt(0.5 * (1 + (1 / (sqrt(1 + P * P)))));
    return std::make_pair(sinf, cosf);
}

double JacobiEigenvectors::find_max_in_over_diagonal_matrix(const vector<vector<double>> &matr)
{
    double max = std::numeric_limits<double>::min();
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = i + 1; j < matr.size(); ++j) {
            if (matr[i][j] > max) {
                max = matr[i][j];
            }
        }
    }

    return max;
}

vector<pair<size_t, size_t>> JacobiEigenvectors::find_indexes_of_over_diagonal_matrix_elements(size_t dimention)
{
    vector<pair<size_t, size_t>> indexes;
    for (size_t i = 0; i < dimention; ++i) {
        for (size_t j = dimention - 1; j >= i + 1; --j) {
            indexes.push_back(std::make_pair(i, j));
        }
    }

    return indexes;
}

vector<vector<double>> JacobiEigenvectors::calc_rotate_matrix(double sin, double cos, size_t i, size_t j, size_t n)
{
    vector<vector<double>> rotate_matrix(n, vector<double>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        rotate_matrix[i][i] = 1;
    }

    rotate_matrix[i][i] = cos;
    rotate_matrix[j][j] = cos;

    rotate_matrix[j][i] = sin;
    rotate_matrix[i][j] = -sin;

    return rotate_matrix;
}
