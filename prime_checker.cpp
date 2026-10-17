#include <iostream>
#include <vector>

// Checks if a number is prime in O(sqrt(n)) time
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true; // 2 and 3 are prime

    // Eliminate multiples of 2 and 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check factors of form 6k +/- 1 up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Generates all primes up to limit using the Sieve of Eratosthenes
std::vector<int> sieveOfEratosthenes(int limit) {
    if (limit < 2) return {};

    std::vector<bool> isPrimeList(limit + 1, true);
    isPrimeList[0] = isPrimeList[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrimeList[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrimeList[multiple] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrimeList[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    std::cout << "--- Prime Number Check ---\n";
    int testNumbers[] = {1, 2, 17, 25, 29, 49, 97};

    for (int num : testNumbers) {
        std::cout << num << " is " << (isPrime(num) ? "prime" : "not prime") << "\n";
    }

    std::cout << "\n--- Sieve of Eratosthenes (Primes up to 50) ---\n";
    int limit = 50;
    std::vector<int> primes = sieveOfEratosthenes(limit);

    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i] << (i + 1 < primes.size() ? ", " : "\n");
    }

    return 0;
}
