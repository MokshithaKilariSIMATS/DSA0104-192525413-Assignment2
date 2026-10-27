#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    long long transactions[10];
    int count;
    int next;
public:
    SavingsAccount(const string& number, long long openingBalance)
        : accountNumber(number), balance(openingBalance), transactions{}, count(0), next(0) {}
    void deposit(long long amount);
    bool withdraw(long long amount);
    void miniStatement() const;
    long long getBalance() const { return balance; }
};

void SavingsAccount::deposit(long long amount) {
    if (amount <= 0) return;
    balance += amount;
    transactions[next] = amount;
    next = (next + 1) % 10;
    if (count < 10) ++count;
}
bool SavingsAccount::withdraw(long long amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    transactions[next] = -amount;
    next = (next + 1) % 10;
    if (count < 10) ++count;
    return true;
}
void SavingsAccount::miniStatement() const {
    cout << "Account " << accountNumber << " | Balance: " << balance << '\n';
    cout << "Recent transactions (oldest to newest):\n";
    int start = (count == 10) ? next : 0;
    for (int i = 0; i < count; ++i)
        cout << transactions[(start + i) % 10] << '\n';
}
int main() {
    SavingsAccount account("SA1024", 1000);
    account.deposit(500);
    account.withdraw(200);
    account.deposit(100);
    account.miniStatement();
}