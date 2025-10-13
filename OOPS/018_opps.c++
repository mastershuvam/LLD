#include <iostream>
#include <exception>
using namespace std;

// Exception for invalid amount input
class InvalidAmountException : public runtime_error {
public:
    InvalidAmountException(const string &msg) : runtime_error(msg) {}
};

// Exception for insufficient balance
class InsufficientBalanceException : public runtime_error {
public:
    InsufficientBalanceException(const string &msg) : runtime_error(msg) {}
};


// Customer class definition
class Customer {
    string name;
    int balance;

public:
    // Constructor
    Customer(const string &customerName, int initialBalance) {
        name = customerName;
        balance = initialBalance;
    }

    // Deposit function
    void deposit(int amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Deposit amount must be greater than zero.");
        }
        balance += amount;
        cout << " Deposit successful! Current balance: ₹" << balance << endl;
    }

    // Withdraw function
    void withdraw(int amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Withdrawal amount must be greater than zero.");
        }
        if (balance < amount) {
            throw InsufficientBalanceException("Withdrawal failed: Insufficient balance.");
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: ₹" << balance << endl;
    }

    // Display customer details
    void display() const {
        cout << "\n Customer Details: \n";
        cout << "Name: " << name << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

// Main function
int main() {
    Customer customer1("Rahul Sharma", 500);
    customer1.display();

    try {
        customer1.deposit(-50);     // invalid deposit
        customer1.withdraw(1000);   // will not execute due to first exception
    }
    catch (const InvalidAmountException &e) {
        cout << "\n[Invalid Amount Error] " << e.what() << endl;
    }
    catch (const InsufficientBalanceException &e) {
        cout << "\n[Insufficient Balance Error] " << e.what() << endl;
    }
    catch (const exception &e) {
        cout << "\n[General Error] " << e.what() << endl;
    }

    return 0;
}
