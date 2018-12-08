#ifndef JACOBI_H
#define JACOBI_H

#include <vector>

using std::vector;
using std::size_t;
using std::pair;

// see
// mathhelpplanet.com/static.php?p=metody-resheniya-zadach-o-sobstvennykh-znacheniyakh-i-vektorakh-matritsy
// for more details
class JacobiEigenvectors
{
public:
    static int jacobi(const vector<vector<double>> &matr, vector<double> &numbers, vector<vector<double>> &vectors);
private:
    static pair<double, double> calc_rotation_sin_cos(const vector<vector<double>> &matr, size_t i, size_t j);

    static vector<vector<double>> calc_rotate_matrix(double sin, double cos, size_t i, size_t j, size_t n);

    static vector<pair<size_t, size_t>> find_indexes_of_over_diagonal_matrix_elements(size_t dimention);

    static double find_max_in_over_diagonal_matrix(const vector<vector<double>> &matr);
};

#endif // JACOBI_H
