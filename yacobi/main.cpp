#include <iostream>
#include <vector>
#include <algorithm>

#include "jacobi.h"

using namespace std;

int main() {
    vector<vector<double>> A = {
        {1.21, -5, 12.2, 31},
        {-5, 2.12, 3.1, -4.3},
        {12.2, 3.1, 10, -3},
        {31, -4.3, -3, 1}
    };


    vector<double> numbers;
    vector<vector<double>> vectors;

    JacobiEigenvectors::jacobi(A, numbers, vectors);

    cout << "Own numbers:" << endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << endl;
    }

    cout << endl << "Eigenvectors:" << endl;
    for (size_t i = 0; i < vectors.size(); ++i) {
        cout << "S" << i + 1 << ":" << endl;
        for (size_t j = 0; j < vectors[i].size(); ++j) {
            cout << vectors[i][j] << endl;
        }
    }

    return 0;
}
