#include <iostream>
#include <string>
using namespace std;

class ATM
{
private:
    long int accNumber;
    int pinCode;
    string holderName;
    double balance;
    long long int mobileNumber;

public:
    void setDetails(long int acc, int pin, string name, double bal, long long int mobile)
    {
        accNumber = acc;
        pinCode = pin;
        holderName = name;
        balance = bal;
        mobileNumber = mobile;
    }

    long int getAccountNumber() { return accNumber; }
    int getPin() { return pinCode; }
    string getName() { return holderName; }
    double getBalance() { return balance; }
    long long int getMobile() { return mobileNumber; }

    void updateMobile(long long int oldMobile, long long int newMobile)
    {
        if (oldMobile == mobileNumber)
        {
            mobileNumber = newMobile;
            cout << "Mobile number updated.\n";
        }
        else
        {
            cout << "Old mobile number incorrect.\n";
        }
        cin.ignore();
        cin.get();
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful.\nBalance: " << balance << "\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
        cin.ignore();
        cin.get();
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Please collect your cash.\nBalance: " << balance << "\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount.\n";
        }
        cin.ignore();
        cin.get();
    }
};

int main()
{
    ATM user;
    user.setDetails(98765432, 2025, "Mohith", 75000.0, 9123456789);

    long int acc;
    int pin, choice;
    do
    {
        system("clear"); // use "cls" if you're on Windows
        cout << "Enter Account Number: ";
        cin >> acc;
        cout << "Enter PIN: ";
        cin >> pin;

        if (acc == user.getAccountNumber() && pin == user.getPin())
        {
            do
            {
                system("clear"); // use "cls" if you're on Windows
                cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Account Info\n5. Update Mobile\n6. Exit\n";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "Balance: " << user.getBalance() << "\n";
                    cin.ignore();
                    cin.get();
                }
                else if (choice == 2)
                {
                    double amt;
                    cout << "Enter deposit amount: ";
                    cin >> amt;
                    user.deposit(amt);
                }
                else if (choice == 3)
                {
                    double amt;
                    cout << "Enter withdrawal amount: ";
                    cin >> amt;
                    user.withdraw(amt);
                }
                else if (choice == 4)
                {
                    cout << "Name: " << user.getName() << "\nAccount: " << user.getAccountNumber()
                         << "\nBalance: " << user.getBalance() << "\nMobile: " << user.getMobile() << "\n";
                    cin.ignore();
                    cin.get();
                }
                else if (choice == 5)
                {
                    long long int oldM, newM;
                    cout << "Enter old mobile: ";
                    cin >> oldM;
                    cout << "Enter new mobile: ";
                    cin >> newM;
                    user.updateMobile(oldM, newM);
                }
                else if (choice == 6)
                {
                    exit(0);
                }
                else
                {
                    cout << "Invalid choice.\n";
                    cin.ignore();
                    cin.get();
                }
            } while (1);
        }
        else
        {
            cout << "Incorrect account number or PIN.\n";
            cin.ignore();
            cin.get();
        }
    } while (1);

    return 0;
}
