#include <iostream>
#include <vector>

// Generates the first n Fibonacci numbers iteratively (O(n) time, O(1) auxiliary space)
std::vector<long long> generateFibonacci(int n) {
    if (n <= 0) return {};
    if (n == 1) return {0};

    std::vector<long long> fibSequence;
    fibSequence.reserve(n);
    fibSequence.push_back(0);
    fibSequence.push_back(1);

    for (int i = 2; i < n; ++i) {
        fibSequence.push_back(fibSequence[i - 1] + fibSequence[i - 2]);
    }

    return fibSequence;
}

// Computes the nth Fibonacci number recursively
long long fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int count = 10;

    std::cout << "--- Fibonacci Sequence Generation (Iterative) ---\n";
    std::cout << "First " << count << " terms:\n";
    std::vector<long long> sequence = generateFibonacci(count);
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << (i + 1 < sequence.size() ? ", " : "\n");
    }

    std::cout << "\n--- N-th Fibonacci Number (Recursive) ---\n";
    int term = 7;
    std::cout << "Term " << term << " is: " << fibonacciRecursive(term) << "\n";

    return 0;
}
