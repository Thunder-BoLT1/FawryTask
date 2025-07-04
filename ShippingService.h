#ifndef SHIPPINGSERVICE_H
#define SHIPPINGSERVICE_H
#include "ShipableItem.h"
#include <vector>
class ShippingService {
	double feesPerKg;
public:
	ShippingService(int fees);
	double calculateShippingFees(vector<ShipableItem*>&);
	void ShipItems(vector<ShipableItem*>& items);
};
#endif