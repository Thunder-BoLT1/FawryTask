#include <iostream>
#include "E_CommerceSystem.h"
using namespace std;

int main() {
	//Classes Relation is by Assoscitaion because they are seprate entities and cas exist without each other (weak dependency)
	Item *cheese = new Item("Cheese", 100, 3, 20260101);
	Item *biscuits = new Item("Biscuits", 150, 1, 20260501);
	ShipableItem *tv = new ShipableItem("TV", 3000, 2, 3000, -1);
	ShipableItem *mobile = new ShipableItem("Mobile", 2750, 4, 500, -1);

	ShippingService* ShippingCompany = new ShippingService(10); //set feest to 10$ perKg
	E_CommerceSystem system(20250704, ShippingCompany);
	Customer me("Mazen Ahmed", "Zayed", "mazen.00ahmd@gmail.com", "01552252818", 150);
	Cart myCart;
	
	//Add ne Products to the system
	system.addNewProduct(cheese);
	system.addNewProduct(biscuits);
	system.addNewProduct(tv);
	system.addNewProduct(mobile);
	//add the products u want to buy in your cart
	myCart.add(cheese, 1);
	//myCart.add(tv, 1);
	//myCart.add(biscuits, 1);
	system.checkOut(me, myCart);
	myCart.add(biscuits, 1);
	system.checkOut(me, myCart);
	
	//delete dynamically allocated items
	delete ShippingCompany;
	delete cheese;
	delete biscuits;
	delete tv;
	delete mobile;


	return 0;
}
