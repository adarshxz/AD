#include <iostream>
#include <string>
#include <iomanip>

// BankAccount class demonstrating basic OOP concepts in C++
class BankAccount {
private:
    std::string ownerName;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& name, double initialBalance = 0.0)
        : ownerName(name), balance(initialBalance) {}

    // Deposit money into the account
    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposited $" << amount << " | New Balance: $" << balance << "\n";
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Insufficient funds! Available: $" << balance << "\n";
            return;
        }
        balance -= amount;
        std::cout << "Withdrew  $" << amount << " | New Balance: $" << balance << "\n";
    }

    // Display account information
    void displayInfo() const {
        std::cout << "Owner  : " << ownerName << "\n";
        std::cout << "Balance: $" << balance << "\n";
    }

    // Getter for balance
    double getBalance() const { return balance; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--- Bank Account System in C++ ---\n\n";

    BankAccount account("Adarsh Singh", 1000.00);

    std::cout << "Account Details:\n";
    account.displayInfo();

    std::cout << "\nTransactions:\n";
    account.deposit(500.00);
    account.withdraw(200.00);
    account.withdraw(2000.00); // Should show insufficient funds
    account.deposit(-100.00);  // Should show error

    std::cout << "\nFinal Account Details:\n";
    account.displayInfo();

    return 0;
}
