#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountId;
    double balance;
    int *transactionHistory;
    int numTransactions;
public:
    BankAccount(int id, double balance, int *transactions, int count) : accountId(id), balance(balance), numTransactions(count) {
        transactionHistory = new int[count];
        for (int i = 0; i < count; i++)
            transactionHistory[i] = transactions[i];
    }

    BankAccount(const BankAccount& obj) : accountId(obj.accountId), balance(obj.balance), numTransactions(obj.numTransactions) {
        transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++)
            transactionHistory[i] = obj.transactionHistory[i];
    }

    ~BankAccount() {
        delete[] transactionHistory;
    }

    void display() {
        cout << "ID: " << accountId << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Number of transactions: " << numTransactions << "\n";
        for (int i = 0; i < numTransactions; i++)
            cout << "Transaction[" << i+1 << "]: " << transactionHistory[i] << "\n";
    }

    void updateTransactionHistory(int *transactions, int count) {
        delete[] transactionHistory;

        transactionHistory = new int[count];
        for (int i = 0; i < count; i++)
            transactionHistory[i] = transactions[i];
    }
};

int main() {
    int history[2] = {200, 300};

    BankAccount account1(0003, 3000.f, history, 2);
    BankAccount copy_account1(account1);

    account1.display();
    copy_account1.display();

    int modifiedHistory[2] = {3, 4};
    account1.updateTransactionHistory(modifiedHistory, 2);

    account1.display();
    copy_account1.display();

    return 0;
}
