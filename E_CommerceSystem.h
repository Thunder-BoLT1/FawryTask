#ifndef E_COMMERCESYSTEM_H
#define E_COMMERCESYSTEM_H
#include <unordered_map>
#include "ShipableItem.h"
#include "ShippingService.h"
#include "Cart.h"
#include "Customer.h"

class E_CommerceSystem {
	unordered_map<string, Item*> allItems; //Map Items Using thier names for easy and fast access using Hashing O(1) Lookup and inseert operations
	ShippingService* ShippingCompany;
	int todayDate;
public:
	E_CommerceSystem(int date, ShippingService*);
	int getTodayDate();
	void addNewProduct(Item*);
	void decrementQuanitiy(string n, int q);
	int getCurrItemQuantity(string n);
	void checkOut(Customer& customer, Cart& cart);

};
#endif // !E_COMMERCESYSTEM_H