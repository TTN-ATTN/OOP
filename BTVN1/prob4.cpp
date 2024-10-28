#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Applies the cat map transformation to a matrix.
 *
 * Transforms the given matrix using the cat map transformation rules.
 *
 * @param matrix The input matrix to be transformed.
 * @param m The size of the matrix (m x m).
 * @return The transformed matrix.
 */
vector<vector<int>> cat_map(const vector<vector<int>>& matrix, int m) {
    vector<vector<int>> transformed(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = (2 * i + j) % m;
            int y = (i + j) % m;
            transformed[x][y] = matrix[i][j];
        }
    }
    return transformed;
}

/**
 * @brief Compares two matrices for equality.
 *
 * Checks if two matrices are equal by comparing their elements.
 *
 * @param mat1 The first matrix to compare.
 * @param mat2 The second matrix to compare.
 * @return True if the matrices are equal, false otherwise.
 */
bool equal(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Solves for the cycle length of the cat map transformation.
 *
 * Applies the cat map transformation repeatedly until the matrix returns to its initial state.
 *
 * @param initialMatrix The initial matrix to start the transformation.
 * @param m The size of the matrix (m x m).
 * @return The cycle length of the transformation.
 */
int solve(const vector<vector<int>>& initialMatrix, int m) {
    vector<vector<int>> currentMatrix = initialMatrix;
    int cycleLength = 0;

    do {
        currentMatrix = cat_map(currentMatrix, m);
        cycleLength++;
    } while (!equal(currentMatrix, initialMatrix));

    return cycleLength;
}

int main() {
    int m;
    cout << "Enter matrix size: ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int cycleLength = solve(matrix, m);
    cout << "Cycle length: " << cycleLength << endl;

    return 0;
}