#include <cassert>
#include "TestCollection.h"
#include "../Collection.h"

void testCollection(){
    Collection<int> c1;

    //Testing with empty collection c1
    assert(c1.size() == 0);

    assert(c1.search(5) == false);
    assert(c1.search(2) == false);
    assert(c1.search(1) == false);

    assert(c1.nroccurrences(4) == 0);
    assert(c1.nroccurrences(1) == 0);
    assert(c1.nroccurrences(2) == 0);
    assert(c1.nroccurrences(3) == 0);
    assert(c1.nroccurrences(5) == 0);

    assert(c1.remove(4) == false);
    assert(c1.remove(3) == false);
    assert(c1.remove(2) == false);
    assert(c1.remove(1) == false);

    //Testing again all functions with elements in collection c1
    c1.add(4);
    c1.add(4);
    c1.add(4);
    c1.add(2);
    c1.add(2);
    c1.add(4);
    c1.add(1);

    assert(c1.size() == 3);

    assert(c1.search(5) == false);
    assert(c1.search(2) == true);
    assert(c1.search(1) == true);

    assert(c1.nroccurrences(4) == 4);
    assert(c1.nroccurrences(1) == 1);
    assert(c1.nroccurrences(2) == 2);
    assert(c1.nroccurrences(3) == 0);
    assert(c1.nroccurrences(5) == 0);

    assert(c1.getAt(0) == 4);
    assert(c1.getAt(1) == 2);
    assert(c1.getAt(2) == 1);

    c1.remove(4);
    c1.remove(2);
    c1.remove(1);

    assert(c1.nroccurrences(4) == 3);
    assert(c1.nroccurrences(2) == 1);
    assert(c1.nroccurrences(1) == 0);

    assert(c1.remove(4) == true);
    assert(c1.remove(2) == true);
    assert(c1.remove(1) == false);

    assert(c1.nroccurrences(4) == 2);
    assert(c1.nroccurrences(2) == 0);
    assert(c1.nroccurrences(1) == 0);
}
