#include <iostream>
#include <vector>
#include <iomanip>

// Generates an N x M matrix with consecutive numbers 1 to N*M
std::vector<std::vector<int>> createMatrix(int rows, int cols) {
    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));
    int val = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = val++;
        }
    }
    return mat;
}

// Traverses a matrix in spiral order: O(m * n) time, O(1) auxiliary space
std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};

    std::vector<int> result;
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse Right
        for (int col = left; col <= right; ++col) {
            result.push_back(matrix[top][col]);
        }
        top++;

        // Traverse Down
        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        right--;

        // Traverse Left (if rows remain)
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                result.push_back(matrix[bottom][col]);
            }
            bottom--;
        }

        // Traverse Up (if columns remain)
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    int rows, cols;
    std::cout << "--- Spiral Matrix Traversal ---\n";
    std::cout << "Enter number of rows and columns: ";

    if (!(std::cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        std::cerr << "Invalid dimensions! Rows and columns must be positive." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix = createMatrix(rows, cols);

    std::cout << "\nOriginal Matrix (" << rows << "x" << cols << "):\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val;
        }
        std::cout << "\n";
    }

    std::vector<int> spiral = spiralOrder(matrix);

    std::cout << "\nSpiral Order Traversal:\n";
    for (size_t i = 0; i < spiral.size(); ++i) {
        std::cout << spiral[i] << (i + 1 < spiral.size() ? " -> " : "\n");
    }

    return 0;
}
