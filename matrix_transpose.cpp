#include <iostream>
#include <vector>
#include <iomanip>

// Prints a 2D matrix with uniform column widths
void printMatrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << std::setw(5) << val;
        }
        std::cout << "\n";
    }
}

// Computes the transpose of an M x N matrix
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};

    int rows = mat.size();
    int cols = mat[0].size();
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = mat[i][j];
        }
    }

    return transposed;
}

// Checks if a square matrix is symmetric (A == A^T)
bool isSymmetric(const std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        if (mat[i].size() != static_cast<size_t>(n)) return false;
        for (int j = i + 1; j < n; ++j) {
            if (mat[i][j] != mat[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;
    std::cout << "--- Matrix Transpose ---\n";
    std::cout << "Enter number of rows and columns: ";
    if (!(std::cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        std::cerr << "Invalid matrix dimensions! Rows and columns must be positive." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::cout << "Enter the elements of the " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\nOriginal Matrix (" << rows << "x" << cols << "):\n";
    printMatrix(matrix);

    std::vector<std::vector<int>> transposed = transposeMatrix(matrix);

    std::cout << "\nTransposed Matrix (" << cols << "x" << rows << "):\n";
    printMatrix(transposed);

    if (rows == cols) {
        std::cout << "\nSymmetric check: "
                  << (isSymmetric(matrix) ? "The matrix is SYMMETRIC." : "The matrix is NOT symmetric.")
                  << std::endl;
    }

    return 0;
}
