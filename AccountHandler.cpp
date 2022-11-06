#include "BankingSystem.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"

using namespace std;
AccountHandler::AccountHandler() :numberOfguest(0) {}

void AccountHandler::DepositAccount()
{
	int temp_number;
	double temp_money;
	cout << "Deposit" << std::endl;
	cout << "account number" << std::endl;
	cin >> temp_number;
	cout << "Deposit amount :" << std::endl;
	cin >> temp_money;

	for (int i = 0; i < numberOfguest; i++)
	{
		if (acc_arr[i]->GetNumber()== temp_number)
		{
			acc_arr[i]->Deposit(temp_money);
			cout << "Deposit completed" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	cout << "withdraw" << std::endl;
	cout << "account number :" << std::endl;
	cin >> temp_number;
	cout << "withdraw amount :" << std::endl;
	cin >> temp_money;
	for (int i = 0; i < numberOfguest; i++)
	{
		if (acc_arr[i]->GetNumber() == temp_number)
		{
			acc_arr[i]->Withdraw(temp_money);
			std::cout << "withdraw completed" << std::endl;
			break;
		}
	}
}
void AccountHandler::Display() const
{
	for (int i = 0; i < numberOfguest; i++)
	{
		acc_arr[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void AccountHandler::CreateAccount() {
	int number, balance, type, grade;
	char name[LEN_NAME];
	float interest;
	
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;

	std::cout << "What kind of account do you want?" << std::endl;
	std::cout << "1 : normal account " <<  "\n"<< "2 : saving account " << std::endl;
	std::cin >> type;
	
	switch (type) {
	case ACCOUNT_TYPE::ONLY_DEPOSIT:
		//account[numberOfguest++] = new Account(number, name, balance);
		acc_arr[numberOfguest++] = new Account(number, name, balance);
		break;
	case ACCOUNT_TYPE::NORMAL :
		std::cout << "enter interset rate";
		std::cin >> interest;
		acc_arr[numberOfguest++] = new NormalAccount(number, name, balance, interest);
		break;

	default :
			break;
	}
}
void AccountHandler::ShowMenu() const
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. create account" << std::endl;
	std::cout << "2. deposit" << std::endl;
	std::cout << "3. withdraw" << std::endl;
	std::cout << "4. list clients and accounts" << std::endl;
	std::cout << "5. exit program" << std::endl;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccountHandler::numberOfguest; i++) {
		delete acc_arr[i];
	}
}