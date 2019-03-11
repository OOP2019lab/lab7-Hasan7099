#include <iostream>
using namespace std;


class bankAccount	
{
private:
	int ID;
	float balance; 
	float balanceLimit;
	float *transactions;
	//A dynamic array of size 10, it will keep values of 10 most recent transactions
	int noOfTran;
	//and integer to represent the number of values in transactions array, it will be between 0 and 10
	void addTransaction(float);
	// A untility function to add a value of transaction in transaction array
	//this funtction adds the value at the last index, 
	//if noOfTran=10 then existing values from index 1-8 should be moved left to make space for new value at 9th(last) index
	


public:
	
	bankAccount(int, float, float=100000);
	//Overaloaded constructor that contains

	bankAccount(int, float, float*, int , float=100000);
	//Overloaded constructor that takes the ID, balance, transactions array and size of transaction array and sets the values accordingly.
	//if size odf input array is >10 then only the last 10 values from input array will be stored in transaction array

	~bankAccount();
	//destructor for bankAccount 

	bool withdraw(float);
	//this function will take float value as input
	//if the value is >=balane it will subtract the value from balance and add the -value in transactions array using add transaction utility function

	bool deposit(float);
	//this function will take float value as input
	//it will add the value in balance and value in transactions array using add transaction utility function
	
	void print();
	// this function will print the information of this bankAccunt

	int getID(){return ID;}

	float get_balance() { return balance; }
	int get_transactions() { return noOfTran; }

};
