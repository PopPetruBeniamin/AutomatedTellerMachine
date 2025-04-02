#include <iostream>
#include <cassert>
#include "TestDynamicVector.h"
#include "../DynamicVector.h"

void testDynamicVector() {
    DynamicVector<int> vec1;
    DynamicVector<int> vec2(5);

    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);

    assert(vec1.size() == 5);
    assert(vec1.getAt(0) == 4);
    assert(vec1.getAt(1) == 5);
    assert(vec1.getAt(2) == 6);
    assert(vec1.getAt(3) == 7);
    assert(vec1.getAt(4) == 8);

    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();

    assert(vec1.size() == 2);
    assert(vec1.getAt(0) == 4);
    assert(vec1.getAt(1) == 5);
    assert(vec1[0] == 4);
    assert(vec1[1] == 5);

    vec1.push_back(5);
    vec1.push_back(5);
    vec1.push_back(4);
    vec1.push_back(7);

    assert(vec1.size() == 6);
    vec1[0] = 100;
    vec1[1] = 100;
    vec1[2] = 100;
    vec1[3] = 100;
    vec1[4] = 100;
    vec1[5] = 100;

    assert(vec1.getAt(0) == 100);
    assert(vec1.getAt(1) == 100);
    assert(vec1.getAt(2) == 100);
    assert(vec1.getAt(3) == 100);
    assert(vec1.getAt(4) == 100);
    assert(vec1.getAt(5) == 100);

    vec1.pop(4);
    assert(vec1.size() == 5);
    assert(vec1.getAt(0) == 100);
    assert(vec1.getAt(1) == 100);
    assert(vec1.getAt(2) == 100);
    assert(vec1.getAt(3) == 100);
    assert(vec1.getAt(4) == 100);


    vec1.pop(4);
    assert(vec1.size() == 4);
    assert(vec1.getAt(0) == 100);
    assert(vec1.getAt(1) == 100);
    assert(vec1.getAt(2) == 100);
    assert(vec1.getAt(3) == 100);
}
