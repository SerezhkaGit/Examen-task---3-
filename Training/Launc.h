#pragma once
#include "FinanceManager.h"
#include "Secure.h"

void Launcher()
{
    PersonalFinanceManager manager;

    setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(1251);

    //���� � ��������
    if (LogIN() == false) { cout << "�� ���������!" << endl; }
   
    else {

        int choice;
        do {
            cout << "\n����:" << endl;
            cout << "1. ������ ��������/�����" << endl;
            cout << "2. ��������� ��������/�����" << endl;
            cout << "3. ������ �������" << endl;
            cout << "4. ����������� ���" << endl;
            cout << "5. �������� ��� � ����" << endl;
            cout << "6. ����������� �����" << endl;
            cout << "0. �����" << endl;
            cout << "\n������ ��: ";
            cin >> choice;
            system("cls");

            switch (choice) {
            case 1: {
                string name;
                double balance;
                int code;

                cout << "������ ����� �������/�����: ";
                cin >> name;

                cout << "������ ���������� ������: ";
                cin >> balance;

                cout << "���������e ���: ";
                cin >> code;

                Wallet wallet = { name, balance, code };
                manager.addWallet(wallet);

                system("cls");
                break;
            }
            case 2: {
                string name;             
                int code;

                cout << "������ ����� �������/����� ��� ����������: ";
                cin >> name;

                cout << "������ ���: ";
                cin >> code;

                manager.deposit(name, code);
               
                break;
            }
            case 3: {
              
                string name;
                int code;

                cout << "������ ����� �������/�����: ";
                cin >> name;

                cout << "������ ���: ";
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

                cout << "������ ����� �������/�����: ";
                cin >> name;

                cout << "������ ���: ";
                cin >> code;

                manager.show_card(name, code);
                break;
            }
            case 0:
                cout << "�� ���������!" << endl;
       
                break;
            default:
                cout << "������� ����. ���� �����, ������ ��������� ����� �����." << endl;
            }
        } while (choice != 0);
    }
}