#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;
class Item
{
	string _Name;
	double _Price;
	int _Quantitiy, _expireDate;
public:
	Item(string n, double p, int q, int d = -1);
	//Setters
	void setName(string n);
	void setPrice(double p);
	void setQuantity(int q);
	void setExpireDate(int e);
	//Getters
	string getName();
	double getPrice();
	int getQuantity();
	int getExpireDate();
	//Utility Functions
	virtual Item* createCopy();
	void printCheckoutData();
};
ostream& operator<<(ostream& o, Item& item);
#endif

