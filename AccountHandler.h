
#ifndef _ACCOUNTHANDLER_H
#define _ACCOUNTHANDLER_H
#include "Account.h"
#include "BoundCheckArray.h"
typedef Account* Account_ptr;
class AccountHandler {
public:
	int numberOfguest;
	BoundCheckArray<Account_ptr> acc_arr;
	AccountHandler();
	~AccountHandler();
public:
	void ShowMenu() const;
	void CreateAccount();
	void DepositAccount();
	void WithdrawMoney();
	void Display() const;
};
#endif

