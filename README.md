sample Input(1) :
	myCart.add(cheese, 2);
	myCart.add(biscuits, 1);
	system.checkOut(me, myCart);
 Sample  Output(1) :
 
 ** Checkout receipt **
------------
Subtotal        350
Shipping        0
Amount  350
Current Balance 650

############

sample Input(2) : 
 	myCart.add(cheese, 2);
	myCart.add(mobile, 1);
	system.checkOut(me, myCart);
 
 sample Output(2) : 
 
   ** Shipment notice **
1xMobile                500g
Total package weight 0.5kg
** Checkout receipt **
------------
Subtotal        2950
Shipping        10
Amount  2960
Current Balance 40

##############
sample Input(3) :
	myCart.add(cheese, 4); // N.B : Only 3 maximum cheese exists in the system
	myCart.add(mobile, 1);
	system.checkOut(me, myCart);

 sample Output(3) : 
 
 ** Shipment notice **
1xMobile                500g
Total package weight 0.5kg
** Checkout receipt **
------------
Subtotal        2750
Shipping        10
Amount  2760
Current Balance 240

##############
sample Input(4) :
	myCart.add(tv, 1); # Tv price is 3000 and shipping fees  = 30 so total 3030 but customer has only 3000
	system.checkOut(me, myCart);

 sample Output(4) : 
 Insuffeicent Balance Missing Shipping Fees

##############

 sample Input(5) :
	system.checkOut(me, myCart);

 sample Output(4) : 
Empty Cart
 ##############

 sample Input(6) :
 	myCart.add(cheese, 1); # ie cheese has expire date 20250101 while toays date is set as 20250704
	system.checkOut(me, myCart);

 sample Output(6) : 
Cheese Has Expired
