#include <iostream>
#include <vector>

// Prints a 2D matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}

// Adds two matrices of the same dimensions
std::vector<std::vector<int>> addMatrices(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B) {
    int rows = A.size(), cols = A[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Multiplies two matrices (A: m x n, B: n x p)
std::vector<std::vector<int>> multiplyMatrices(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    std::vector<std::vector<int>> result(m, std::vector<int>(p, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

int main() {
    std::vector<std::vector<int>> A = {{1, 2, 3},
                                       {4, 5, 6}};

    std::vector<std::vector<int>> B = {{7, 8, 9},
                                       {1, 2, 3}};

    std::vector<std::vector<int>> C = {{1, 2},
                                       {3, 4},
                                       {5, 6}};

    std::cout << "--- Matrix Operations in C++ ---\n\n";

    std::cout << "Matrix A (2x3):\n";
    printMatrix(A);

    std::cout << "\nMatrix B (2x3):\n";
    printMatrix(B);

    std::cout << "\nA + B:\n";
    printMatrix(addMatrices(A, B));

    std::cout << "\nMatrix C (3x2):\n";
    printMatrix(C);

    std::cout << "\nA x C (2x3 * 3x2 = 2x2):\n";
    printMatrix(multiplyMatrices(A, C));

    return 0;
}
