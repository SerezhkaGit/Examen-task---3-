#pragma once
#include "lilbries.h"

class data_system
{
private:
	string path_c;//файл з паролем програми
	string path_l;//файл з логіном користувача

	ifstream Fin;
	ofstream File;
public:
	data_system() : path_c{ "password.txt" }, path_l{"login.txt"} {}
	data_system(string text1, string text2) : path_c{ text1 }, path_l{text2} {}

	string getPath_password()
	{
		return path_c;
	}

	string getPath_login()
	{
		return path_l;
	}

	//void setPath_password()
	//{
	//	string text;
	//	cout << "\nEnter new file_name";
	//	getline(cin, text);
	//	path_c = text;
	//	path_c += ".txt";
	//}

	//void setPath_login()
	//{
	//	string text;
	//	cout << "\nEnter new file_name";
	//	getline(cin, text);
	//	path_l = text;
	//	path_l += ".txt";
	//}


	~data_system() {}

	void create_file()
	{
		//перший файл
		File.open(getPath_password());
		if (File.is_open())
		{
			cout << "\nФайл був створений успішно";
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
		}

		File.close();
		
		//Другий файл
		File.open(getPath_login());
		if (File.is_open())
		{
			cout << "\nФайл був створений успішно";
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
		}

		File.close();

	}

	void load_data(string password, string login)
	{
		
		File.open(getPath_password());
		if (File.is_open())
		{
			File << password;
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
		}

		File.close();
		File.open(getPath_login());
		if (File.is_open())
		{
			File << login;
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
		}

		File.close();
	}

	bool check_password(string pass)
	{

		Fin.open(getPath_password());
		string message;

		if (Fin.is_open())
		{
			while (!Fin.eof())
			{
				Fin >> message;
			}
			if(pass == message)
			{return true;}

			else {
				return false;
			}
			
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
			return false;
		}
		Fin.close();

	}

	bool check_login(string loggin)
	{

		Fin.open(getPath_login());
		string message;

		if (Fin.is_open())
		{
			while (!Fin.eof())
			{
				Fin >> message;
			}
			if(message == loggin)
			{
				return true;
			}
			else {
				return false;
			}
			
		}

		else
		{
			cerr << "\nНе вдалося відкрити файл";
			return false;
		}
		Fin.close();

	}

};
bool LogIN()
{
	int choiser;
	bool controller = true;
	do
	{
		cout << "\n \t\t\t        W E L C O M E" << endl;
		cout << "\n  Enter 0 - to leave";
		cout << "\tEnter 1 - to register";
		cout << "\tEnter 2 - log into the account"<<endl;
		cin >> choiser;
		system("cls");
		
		if (choiser == 0)
		{
			controller = false;
			return false;
			break;
		}
		
		if (choiser == 1)
		{
			string Password, login;
			data_system object;

			cout << "\n Enter your login: ";
			cin.ignore(251, '\n');
			getline(cin, login);

			if (object.check_login(login) == true)
			{
				cout << "\nВи не можете використовувати це ім'я";
				this_thread::sleep_for(chrono::milliseconds(2000));
				system("cls");
				return false;
				break;
			}

			else {

				cout << "\n Enter your pasword: ";
				getline(cin, Password);


				object.load_data(Password, login);
				system("cls");

				cout << "\n\t\t У С П І Х ";

				_getch();
				system("cls");

				return true;
				break;
			}
		}
	
		if (choiser == 2)
		{
			data_system object;
			string log, pas;

			cout << "\nEnter your login: ";
			cin.ignore(251, '\n');
			getline(cin, log);

			if (object.check_login(log) == true)
			{
				cout << "\nEnter your password: ";
				cin.ignore(251, '\n');
				getline(cin, pas);

				if (object.check_password(pas) == true)
				{
					system("cls");
					cout << "\n\t\t У С П І Х";
					this_thread::sleep_for(chrono::milliseconds(2000));
					system("cls");
					return true;
				}
				else {
					cerr << "\n\t Неправильний пароль" << endl;
					this_thread::sleep_for(chrono::milliseconds(2000));
					system("cls");
					return false;
				}
			}

			else
			{
				cerr << "\n\t Неправильний логін"<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				system("cls");
				return false;
			}
		}		
		
	} while (controller);
	
}
