#include <iostream>
#include <cmath>

// Solves Tower of Hanoi problem recursively and prints each move
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod, int& moveCount) {
    if (n == 0) {
        return;
    }

    // Move n - 1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, fromRod, auxRod, toRod, moveCount);

    // Move the nth disk from source to destination rod
    std::cout << "Step " << ++moveCount << ": Move disk " << n
              << " from rod " << fromRod << " to rod " << toRod << "\n";

    // Move n - 1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, auxRod, toRod, fromRod, moveCount);
}

int main() {
    int numDisks;
    std::cout << "--- Tower of Hanoi Solver ---\n";
    std::cout << "Enter the number of disks: ";
    if (!(std::cin >> numDisks) || numDisks <= 0) {
        std::cerr << "Invalid input! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::cout << "\nOptimal sequence of moves for " << numDisks << " disks:\n\n";
    int moveCount = 0;
    towerOfHanoi(numDisks, 'A', 'C', 'B', moveCount);

    std::cout << "\nTotal moves required: " << moveCount
              << " (Formula: 2^n - 1 = " << static_cast<long long>(std::pow(2, numDisks) - 1) << ")\n";

    return 0;
}
