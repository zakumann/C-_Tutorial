	/*
	* Banking System ver 0.1
	* Writter : Seong Woo yoon
	* explain : Template for OOP project
	*/
	#include <iostream>
	#include <cstring>

	using namespace std;
	const int NAME_LEN = 20;

	void ShowMenu(void);//Menu
	void MakeAccount(void);//Integer for Account
	void DepositMoney(void);//Deposit
	void WithdrawMoney(void);//Withdraw
	void ShowAllAccInfo(void);//AccInfo

	enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

	typedef struct
	{
		int accID;//accID
		int balance;//balance
		char cusName[NAME_LEN]; //cusName
	} Account;

	Account accArr[100];	// Account for list
	int accNum = 0;			//number of Account

	int main(void)
	{
		int choice;

		while (1)
		{
			ShowMenu();
			cout << "Choice: ";
			cin >> choice;
			cout << endl;

			switch(choice)
			{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "Illegal selection.." << endl;
			}
		}
		return 0;
	}

	void ShowMenu(void)
	{
		cout << "----Menu----" << endl;
		cout << "1. Establish account" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. WithdDraw" << endl;
		cout << "4. Account Info" << endl;
		cout << "5. End Program" << endl;
	}

	void MakeAccount(void)
	{
		int id;
		char name[NAME_LEN];
		int balance;

		cout << "[Establish account] *Please typing integer, not character." << endl;
		cout << "Account ID :"; cin >> id;
		cout << "Name :"; cin >> name;
		cout << "balance :"; cin >> balance;
		cout << endl;

		accArr[accNum].accID = id;
		accArr[accNum].balance = balance;
		strcpy_s(accArr[accNum].cusName, name);
		accNum++;
	}

	void DepositMoney(void)
	{
		int money;
		int id;
		cout << "[Deposit]" << endl;
		cout << "AccountID : "; cin >> id;
		cout << "Alliance : "; cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i].accID == id)
			{
				accArr[i].balance += money;
				cout << "Deposite complete" << endl << endl;
			}else
			cout << "Invalid ID" << endl << endl;
		}
		
	}

	void WithdrawMoney(void)
	{
		int money;
		int id;
		cout << "[Widthdraw]" << endl;
		cout << "Account ID : "; cin >> id;
		cout << "Alliance : "; cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i].accID == id)
			{
				if (accArr[i].balance < money)
				{
					cout << "Insufficient balance" << endl << endl;
					return;
				}

				accArr[i].balance -= money;
				cout << "Withdrawal complete" << endl << endl;
				return;
			}else
			cout << "Invalid ID" << endl << endl;
		}
		
	}

		void ShowAllAccInfo(void)
		{
			for (int i = 0; i < accNum; i++)
			{
				cout << "AccountID : " << accArr[i].accID << endl;
				cout << "Name : " << accArr[i].cusName << endl;
				cout << "Balance : " << accArr[i].balance << endl << endl;
			}
		}