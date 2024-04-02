#pragma once
#include "FinanceManager.h"
#include "Secure.h"

void Launcher()
{
    PersonalFinanceManager manager;

    setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(1251);

    //вхід в програму
    if (LogIN() == false) { cout << "До побачення!" << endl; }
   
    else {

        int choice;
        do {
            cout << "\nМеню:" << endl;
            cout << "1. Додати гаманець/карту" << endl;
            cout << "2. Поповнити гаманець/карту" << endl;
            cout << "3. Додати витрату" << endl;
            cout << "4. Згенерувати звіт" << endl;
            cout << "5. Зберегти звіт у файл" << endl;
            cout << "6. Переглянути карту" << endl;
            cout << "0. Вийти" << endl;
            cout << "\nОберіть дію: ";
            cin >> choice;
            system("cls");

            switch (choice) {
            case 1: {
                string name;
                double balance;
                int code;

                cout << "Введіть назву гаманця/карти: ";
                cin >> name;

                cout << "Введіть початковий баланс: ";
                cin >> balance;

                cout << "Придумайтe код: ";
                cin >> code;

                Wallet wallet = { name, balance, code };
                manager.addWallet(wallet);

                system("cls");
                break;
            }
            case 2: {
                string name;             
                int code;

                cout << "Введіть назву гаманця/карти для поповнення: ";
                cin >> name;

                cout << "Введіть код: ";
                cin >> code;

                manager.deposit(name, code);
               
                break;
            }
            case 3: {
              
                string name;
                int code;

                cout << "Введіть назву гаманця/карти: ";
                cin >> name;

                cout << "Введіть код: ";
                cin >> code;

                manager.addExpense(name, code);
            
              
                break;
            }
            case 4: {
                manager.generateReport();
                this_thread::sleep_for(chrono::milliseconds(5000));
                system("cls");
                break;
            }
            case 5: {
                string path_name;
                cout << "\nEnter the new file_name: ";
                cin.ignore(251, '\n');
                getline(cin, path_name);

                manager.saveReportToFile(path_name);
                this_thread::sleep_for(chrono::milliseconds(9000));
                system("cls");
                break;
            }
            case 6: {
                
                string name;
                int code;

                cout << "Введіть назву гаманця/карти: ";
                cin >> name;

                cout << "Введіть код: ";
                cin >> code;

                manager.show_card(name, code);
                break;
            }
            case 0:
                cout << "До побачення!" << endl;
       
                break;
            default:
                cout << "Невірний вибір. Будь ласка, введіть коректний номер опції." << endl;
            }
        } while (choice != 0);
    }
}