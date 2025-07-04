#ifndef CART_H
#define CART_H
#include <vector>
#include "ShipableItem.h"

class E_CommerceSystem;

class Cart {
	vector<Item*> cartItems;
public:
	bool add(Item* item, int q);
	bool Validate(int Balance, double& totalPrice, E_CommerceSystem* system);
	void GetShipableItems(vector<ShipableItem*>& shippedItems);
	void ConfirmCheckout(E_CommerceSystem* system);
	void printItems();
	~Cart();
};
#endif