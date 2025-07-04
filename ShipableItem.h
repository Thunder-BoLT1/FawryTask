#ifndef SHIPABLEITEM_H
#define SHIPABLEITEM_H
#include "Item.h"
// here i will inherit from class Item another class to represent the Shipable items
class ShipableItem : public Item {
	double _Weight;
public:
	ShipableItem(string n, double p, int q, double w, int d = -1);
	//Setters
	void setWeight(double w);
	//Getters
	double getWeight();
	//Utility Functions
	virtual Item* createCopy();
	void printShippingData();
};
#endif