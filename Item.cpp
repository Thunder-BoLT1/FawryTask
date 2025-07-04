#include "Item.h"
Item::Item(string n, double p, int q, int d) {
	//It's always better to add setters and getters for private members for data validation
	setName(n);
	setPrice(p);
	setQuantity(q);
	setExpireDate(d);
}
//Setters
void Item::setName(string n) { _Name = n; }
void Item::setPrice(double p) { if (p >= 0) _Price = p; } // Item Can be free but can't be with negative price
void Item::setQuantity(int q) { if (q >= 0) _Quantitiy = q; }
void Item::setExpireDate(int e) { _expireDate = e; }
//Getters
string Item::getName() { return _Name; }
double Item::getPrice() { return _Price; }
int Item::getQuantity() { return _Quantitiy; }
int Item::getExpireDate() { return _expireDate; }
//Utility Functions
Item* Item::createCopy() {
	return new Item(*this);
}
void Item::printCheckoutData() {
	cout << this << "\t\t" << _Price << endl;
}
ostream& operator<<(ostream& o, Item& item) {
	o << item.getQuantity() << "x" << item.getName();
	return o;
}