#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
using namespace std;
//Assume there is a customer class Wih blueprint maybe like this
class Customer {
	//these information must be encrypted and stored in a secure database
	string _Name, _Address, _Email, _PhoneNumber;
	double currBalance;
public:
	Customer(string n, string a, string e, string p, double b);
public:
	void decrementCurrBalance(double dec);
	double getCurrBalance();
};
#endif
