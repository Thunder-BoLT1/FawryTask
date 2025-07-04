#include "E_CommerceSystem.h"

E_CommerceSystem::E_CommerceSystem(int date, ShippingService* company) : todayDate(date), ShippingCompany(company) {}
int E_CommerceSystem::getTodayDate() { return todayDate; }
void E_CommerceSystem::addNewProduct(Item* newProduct) {
	allItems[newProduct->getName()] = newProduct;
}
void E_CommerceSystem::decrementQuanitiy(string n, int q) {
	Item* item = allItems[n];
	if (item && item->getQuantity() >= q) item->setQuantity(item->getQuantity() - q);
	if (item->getQuantity() == 0) {
		allItems.erase(n);
	}
}
int E_CommerceSystem::getCurrItemQuantity(string n) {
	if (allItems[n]) return allItems[n]->getQuantity();
	else return 0;
}
void E_CommerceSystem::checkOut(Customer& customer, Cart& cart) {
	double subtotalPrice = 0, shippingFees;
	vector<ShipableItem*> shippedItems;
	if (cart.Validate(customer.getCurrBalance(), subtotalPrice, this)) {
		cart.GetShipableItems(shippedItems);
		shippingFees = ShippingCompany->calculateShippingFees(shippedItems);
		if (subtotalPrice + shippingFees > customer.getCurrBalance()) {
			cout << "Insuffeicent Balance Missing Shipping Fees" << endl;
			return;
		}
		cart.ConfirmCheckout(this);
		if(!shippedItems.empty()) ShippingCompany->ShipItems(shippedItems);
		customer.decrementCurrBalance(subtotalPrice + shippingFees);
		cout << "** Checkout receipt **" << endl;
		cart.printItems();
		cout << "------------" << endl;
		cout << "Subtotal\t" << subtotalPrice << endl;
		cout << "Shipping\t" << shippingFees << endl;
		cout << "Amount\t" << subtotalPrice + shippingFees << endl;
		cout << "Current Balance\t" << customer.getCurrBalance() << endl;
	}
}
