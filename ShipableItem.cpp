#include "ShipableItem.h"
ShipableItem::ShipableItem(string n, double p, int q, double w, int d) : Item(n, p, q, d) {
	setWeight(w);
}
//Setters
void ShipableItem::setWeight(double w) { if (w > 0) _Weight = w; }
//Getters
double ShipableItem::getWeight() { return _Weight; }
//Utility Functions
Item* ShipableItem::createCopy() {
	return new ShipableItem(*this);
}
void ShipableItem::printShippingData() {
	cout << *this << "\t\t" << _Weight * getQuantity() << "g" << endl;
}
