#include <cassert>
#include <iostream>
#include "testBanknoteQuantity.h"
#include "BanknoteQuantity.h"

void testBanknoteQuantity(){
    BanknoteQuantity b1, b2(200, 40), b3(b2);

    //==================Testing get functions==================
    //b1
    assert(b1.getBanknote() == 0);
    assert(b1.getQuantity() == 0);

    //b2
    assert(b2.getBanknote() == 200);
    assert(b2.getQuantity() == 40);

    //b3
    assert(b3.getBanknote() == 200);
    assert(b3.getQuantity() == 40);

    //==================Testing set functions==================
    b1.setBanknote(10);
    b1.setQuantity(11);
    b2.setBanknote(20);
    b2.setQuantity(5);
    b3.setBanknote(100);
    b3.setQuantity(47);


    assert(b1.getBanknote() == 10);
    assert(b1.getQuantity() == 11);
    assert(b2.getBanknote() == 20);
    assert(b2.getQuantity() == 5);
    assert(b3.getBanknote() == 100);
    assert(b3.getQuantity() == 47);

    //==================Testing operator functions==================
    assert(b1 < b2);
    assert(b2 < b3);
    assert(b2 > b1);
    assert(b3 > b2);

    assert(b1 <= b2);
    assert(b2 <= b3);
    assert(b2 >= b1);
    assert(b3 >= b2);

    assert((b1 == b2) == 0);
    assert((b1 == b3) == 0);
    assert((b2 == b3) == 0);

    b2 = b1;
    b3 = b2;

    assert(b1 == b2);
    assert(b1 == b3);
    assert(b2 == b3);
}
