#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

// Generates Pascal's Triangle with 'numRows' rows
std::vector<std::vector<int>> generatePascalsTriangle(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle;
}

// Prints Pascal's Triangle in a formatted pyramid shape
void printPascalsTriangle(const std::vector<std::vector<int>>& triangle) {
    int numRows = triangle.size();
    for (int i = 0; i < numRows; ++i) {
        // Leading spaces for pyramid alignment
        std::cout << std::string((numRows - i - 1) * 2, ' ');
        for (int val : triangle[i]) {
            std::cout << std::setw(4) << val;
        }
        std::cout << "\n";
    }
}

int main() {
    int rows;
    std::cout << "Enter number of rows for Pascal's Triangle: ";
    if (!(std::cin >> rows) || rows <= 0) {
        std::cerr << "Invalid input! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> triangle = generatePascalsTriangle(rows);

    std::cout << "\nPascal's Triangle (" << rows << " rows):\n\n";
    printPascalsTriangle(triangle);

    return 0;
}
