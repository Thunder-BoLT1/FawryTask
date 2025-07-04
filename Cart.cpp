#include "Cart.h"
#include "E_CommerceSystem.h"

//Important to compare dates and detect expred products date is in the form yy/mm/dd if product has no expire date it's -1
bool isExpired(int expireDate, int todayDate) {
	if (expireDate == -1) return false;
	if (expireDate / 10000 != todayDate / 10000) return (expireDate / 10000 < todayDate / 10000);
	else if ((expireDate / 100) % 100 != (todayDate / 100) % 100) return (expireDate / 100) % 100 < (todayDate / 100) % 100;
	else return	expireDate % 100 < todayDate % 100;
	return false;
}

bool Cart::add(Item* item, int q) {
	if (item->getQuantity() >= q) {
		Item* newItem = item->createCopy();
		newItem->setQuantity(q);
		cartItems.push_back(newItem);
		return true;
	}
	return false;
}
bool Cart::Validate(int Balance, double& subtotalPrice, E_CommerceSystem* system) {
	subtotalPrice = 0;
	if (cartItems.empty()) {
		cout << "Empty Cart" << endl;
		return false;
	}
	for (int i = 0; i < cartItems.size(); i++) {
		int checkoutQuantity = cartItems[i]->getQuantity();
		int availQuantity = system->getCurrItemQuantity(cartItems[i]->getName());
		int expireDate = cartItems[i]->getExpireDate();
		int todayDate = system->getTodayDate();
		if (checkoutQuantity > availQuantity) {
			cout << "No Stock Available for" << cartItems[i]->getName() << endl;
			return false;
		}
		if (isExpired(expireDate, todayDate)) {
			cout << cartItems[i]->getName() << " Has Expired " << endl;
			return false;
		}
		subtotalPrice += checkoutQuantity * cartItems[i]->getPrice();
		if (subtotalPrice > Balance) {
			cout << "Current Balance is not Suffiecient" << endl;
			return false;
		}
	}
	return true;
}
void Cart::GetShipableItems(vector<ShipableItem*>& shippedItems) {
	for (int i = 0; i < cartItems.size(); i++) {
		ShipableItem* item = dynamic_cast<ShipableItem*>(cartItems[i]);
		if (item) { shippedItems.push_back(item); }
	}
}
void Cart::ConfirmCheckout(E_CommerceSystem* system) {
	for (int i = 0; i < cartItems.size(); i++) { system->decrementQuanitiy(cartItems[i]->getName(), cartItems[i]->getQuantity()); }
	cartItems.clear();
}
void Cart::printItems() {
	for (int i = 0; i < cartItems.size(); i++) {
		cout << *cartItems[i] << "\t\t" << cartItems[i]->getPrice() * cartItems[i]->getQuantity() << endl;
	}
}
Cart::~Cart() {
	for (int i = 0; i < cartItems.size(); i++) delete cartItems[i];
}