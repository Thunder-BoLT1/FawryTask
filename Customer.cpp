#include "Customer.h"

Customer::Customer(string n, string a, string e, string p, double b) :_Name(n), _Address(a), _Email(e), _PhoneNumber(p), currBalance(b) {}
void Customer::decrementCurrBalance(double dec) { currBalance -= dec; }
double Customer::getCurrBalance() { return currBalance; }
