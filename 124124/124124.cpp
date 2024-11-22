#include <iostream>
using namespace std;
#include <string>


class BankAccount
{
private:
    int accountNumber;
    int balance;

public:

    BankAccount(int accountNumber, int balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }


    int getterAccNumber()
    {
        return accountNumber;
    }

    int getterBalance()
    {
        return balance;
    }

    void setterAccNumber(int accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    void setterBalance(int balance)
    {
        this->balance = balance;
    }

    void Deposit(int amount)
    {
        this->balance = this->balance + amount;
    }

    void Withdraw(int amount)
    {
        this->balance = this->balance - amount;
    }



};


int main()
{
    BankAccount cont1(69, 420);
    cout << cont1.getterAccNumber() << endl;
    cout << cont1.getterBalance() << endl;

    cont1.setterAccNumber(690);
    cont1.setterBalance(4200);

    cout << cont1.getterAccNumber() << endl;
    cout << cont1.getterBalance() << endl;

    cont1.Deposit(100);
    cout << cont1.getterBalance() << endl;
    cont1.Withdraw(200);
    cout << cont1.getterBalance() << endl;
    






}

