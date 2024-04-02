
#pragma once
#include "lilbries.h"


//структура для витрат
struct Expense
{
    string category;
    double amount;

};

// Структура для представлення гаманців і карт
struct Wallet
{
    string name;
    double balance;
    int code;
};

class PersonalFinanceManager
{
private:
    vector<Wallet> wallets;
    vector<Expense> expenses;

public:
    // Додавання нового гаманця або карти
    void addWallet(const Wallet& wallet)
    {
        wallets.push_back(wallet);
    }

    // Поповнення гаманця або карти
    void deposit(const string& walletName,  int wcode)
    {
        for (auto& wallet : wallets) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            if (wallet.name == walletName && wallet.code == wcode)
            {
                int amount;

                cout << "Введіть суму для поповнення: ";
                cin >> amount;
                wallet.balance += amount;
                break;
            }

            else {
                cout << "\nYou don't have such card/wallet";
                break;
            }
        }
    }

    // Додавання нової витрати
    void addExpense(const string& walletName, int wcode)
    {
        for (auto& wallet : wallets) 
        {
            if (wallet.name == walletName && wallet.code == wcode)
            {
                string category;
                double amount;

                cout << "Введіть категорію витрати: ";
                cin >> category;

                cout << "Введіть суму витрати: ";
                cin >> amount;
                if (amount > wallet.balance) { cout << "\nНедостатньо коштів на рахунку"; }

                else {
                    wallet.balance -= amount;
                    Expense expense = { category, amount };
                    expenses.push_back(expense);
                }
              
            }

            else 
            {
                cout << "\nYou don't have such card/wallet";         
            }
        }
        
    }

    void show_card( string& walletName, int wcode)
    {
        for (auto& wallet : wallets) 
        {
            if (wallet.name == walletName)
            {
                if (wallet.code == wcode)
                {
                    cout << "\n\t*****************************************";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t      " << walletName;
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*                                       *";
                    cout << "\n\t*****************************************"<<endl;

                    cout << "\n Wallet name: " << walletName;
                    cout << "\n Wallet code: " << wcode;
                    cout << "\n Wallet balance: " << wallet.balance;
                  
                    _getch();
                    system("cls");
                }
                else { cout << "\n Incorrect code"; }
            }

            else 
            {
                cout << "\nYou don't have such card/wallet";
            }
        }
    }

    // Генерація звіту 
    void generateReport() 
    {
        system("cls");
        cout << "\n\t Г Е Н Е Р А Ц І Я   З В І Т У";
        cout << "\n\t-------------------------------" << endl;;
        cout << "\t";
        for (int i = 0; i < 21; i++)
        {
            cout << "*";
            this_thread::sleep_for(chrono::milliseconds(500)); 
        }
        system("cls");
        cout << "\n\t У С П І Х";
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");

        if (wallets.empty()) 
        {
            cout << "No wallets available." << endl;
            return;
        }

     
        Wallet maxBalanceWallet = wallets[0];
        for (const auto& wallet : wallets) 
        {
            if (wallet.balance > maxBalanceWallet.balance) 
            {
                maxBalanceWallet = wallet;
            }
        }

        cout << "\nWallet with the highest balance:" << endl;
        cout << "\nName: " << maxBalanceWallet.name << ", Balance: " << maxBalanceWallet.balance << endl;

       
        cout << "\nWallets:" << endl;
        for (const auto& wallet : wallets) 
        {
            cout << "\nName: " << wallet.name << ", Balance: " << wallet.balance << endl;
        }

        cout << "\nExpenses:" << endl;

        for (const auto& expense : expenses) 
        {
            cout << "Category: " << expense.category << ", Amount: " << expense.amount << endl;
        }
    }
  

    // Збереження звіту у файл
    void saveReportToFile(const string& filename) 
    {
        ofstream outFile(filename);
        if (outFile.is_open()) 
        {
            if (wallets.empty())
            {
                outFile << "No wallets available." << endl;
                return;
            }


            Wallet maxBalanceWallet = wallets[0];
            for (const auto& wallet : wallets)
            {
                if (wallet.balance > maxBalanceWallet.balance)
                {
                    maxBalanceWallet = wallet;
                }
            }

            outFile << "\nWallet with the highest balance:" << endl;
            outFile << "\nName: " << maxBalanceWallet.name << ", Balance: " << maxBalanceWallet.balance << endl;
            
            outFile << "Wallets:" << endl;
            for (const auto& wallet : wallets) 
            {
                outFile << "\nName: " << wallet.name << ", Balance: " << wallet.balance << endl;
            }

            
            outFile << "Expenses:" << endl;
            for (const auto& expense : expenses) 
            {
                outFile << "\nCategory: " << expense.category << ", Amount: " << expense.amount << endl;
            }

            outFile.close();
            cout << "\nReport saved to " << filename << endl;
        }

        else
        {
            cout << "\nUnable to open file " << filename << " for writing." << endl;
        }
    }
};
