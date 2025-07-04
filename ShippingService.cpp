#include "ShippingService.h"

ShippingService::ShippingService(int fees):feesPerKg(fees){}
double ShippingService::calculateShippingFees(vector<ShipableItem*>& Items) {
	double fees = 0;
	for (int i = 0; i < Items.size(); i++) fees += (Items[i]->getQuantity() * ceil(Items[i]->getWeight() / 1000))* feesPerKg;
	return fees;
}
void ShippingService::ShipItems(vector<ShipableItem*>& items) {
	cout << "** Shipment notice **" << endl;
	double totalWeight = 0;
	for (int i = 0; i < items.size(); i++) {
		totalWeight += items[i]->getWeight() * items[i]->getQuantity();
		items[i]->printShippingData();
	}
	cout << "Total package weight " << totalWeight / 1000 << "kg" << endl;
}