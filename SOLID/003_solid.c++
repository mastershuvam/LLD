//Liskov Substitution Principle 


#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

// ---------- Savings Account ----------
class SavingAccount : public WithdrawableAccount {
    double balance;
public:
    SavingAccount() { balance = 0; }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

// ---------- Current Account ----------
class CurrentAccount : public WithdrawableAccount {
    double balance;
public:
    CurrentAccount() { balance = 0; }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

// ---------- Fixed Term Account ----------
class FixedTermAccount : public DepositOnlyAccount {
    double balance;
public:
    FixedTermAccount() { balance = 0; }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

// ---------- Bank Client ----------
class BankClient {
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount*> withdrawableAccounts,
               vector<DepositOnlyAccount*> depositOnlyAccounts) {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        int choice;
        do {
            cout << "\n===== BANK MENU =====\n";
            cout << "1. Deposit to Savings\n";
            cout << "2. Withdraw from Savings\n";
            cout << "3. Deposit to Current\n";
            cout << "4. Withdraw from Current\n";
            cout << "5. Deposit to Fixed Term\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            double amount;
            switch (choice) {
                case 1:
                    cout << "Enter amount to deposit (Savings): ";
                    cin >> amount;
                    withdrawableAccounts[0]->deposit(amount);
                    break;

                case 2:
                    cout << "Enter amount to withdraw (Savings): ";
                    cin >> amount;
                    withdrawableAccounts[0]->withdraw(amount);
                    break;

                case 3:
                    cout << "Enter amount to deposit (Current): ";
                    cin >> amount;
                    withdrawableAccounts[1]->deposit(amount);
                    break;

                case 4:
                    cout << "Enter amount to withdraw (Current): ";
                    cin >> amount;
                    withdrawableAccounts[1]->withdraw(amount);
                    break;

                case 5:
                    cout << "Enter amount to deposit (Fixed Term): ";
                    cin >> amount;
                    depositOnlyAccounts[0]->deposit(amount);
                    break;

                case 0:
                    cout << "Exiting program...\n";
                    break;

                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 0);
    }
};

// ---------- main ----------
int main() {
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient client(withdrawableAccounts, depositOnlyAccounts);
    client.processTransactions();

    return 0;
}
