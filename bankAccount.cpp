#include "bankAccount.h"
#include <algorithm>

void bankAccount::addTransaction(float value)
{
	if (this->noOfTran==10)
	{for (int i=0;i<9;i++)
	{
		this->transactions[i]=this->transactions[i+1];
	}	
	this->noOfTran--;
	}
	this->transactions[noOfTran++]=value;
}

bankAccount::bankAccount(int ID, float balance, float balanceLimit)
	:ID(ID), balance(balance),balanceLimit(balanceLimit)
{
	this->transactions= new float[10];
	this->noOfTran=0;
}
bankAccount::bankAccount(int ID, float balance, float* transactions, int sizeofTran, float balanceLimit)
	:ID(ID), balance(balance),balanceLimit(balanceLimit)
{
	this->transactions= new float[10];
	this->noOfTran=0;
	if(sizeofTran<=10)
	{
		for(int i=0;i<sizeofTran; i++)
			this->addTransaction(transactions[i]);
	}
	else
	{
		for(int i=sizeofTran-1; i>=sizeofTran-10; i--)
			this->transactions[i-(sizeofTran-10)]=transactions[i];
		this->noOfTran=min(sizeofTran,10);
	}
}
bankAccount::~bankAccount()
{
	delete[] this->transactions;
	this->transactions= nullptr;
	this->noOfTran=0;
	cout<<endl<<"Destructor invoked for ID: "<<ID<<endl;
}
bool bankAccount::withdraw(float amount)
{
	if (amount>0)
	{
		if(amount<=this->balance)
		{
			this->balance-=amount;
			this->addTransaction(-1*amount);
			cout<<"Transaction successfull, your balance is "<<this->balance<<endl;
			return true;

		}
		else
		{
			cout<<"Transaction unsucessfull: Insufficient balance"<<endl;
			return false;
		}
	}
	else 
		cout<<"Transaction unsucessfull: Invalid amount"<<endl;
}
bool bankAccount::deposit(float amount)
{
	if (amount>0)
	{
		if((amount+this->balance)<=this->balanceLimit)
		{
			this->balance+=amount;
			this->addTransaction(amount);
			cout<<"Transaction successfull, your balance is "<<this->balance<<endl;
			return true;

		}
		else
		{
			cout<<"Transaction unsucessfull: balance will exceed limit"<<endl;
			return false;
		}
	}
	else 
		cout<<"Transaction unsucessfull: Invalid amount"<<endl;
}
void bankAccount::print()
{
	cout<<"Account ID: "<<this->ID<<endl;
	cout<<"Balance: "<<this->balance<<endl;
	cout<<"Balance Limit: "<<this->balanceLimit<<endl;
	if(noOfTran!=0)
	{
		cout<<"Recent transactions: "<<endl;
		for(int i=0;i<this->noOfTran-1; i++)
			cout<<this->transactions[i]<<", ";
		cout<<this->transactions[this->noOfTran-1]<<endl;
	}
	else
	{
		cout<<" No trasaction"<<endl;
	}
	cout<<endl;
}
