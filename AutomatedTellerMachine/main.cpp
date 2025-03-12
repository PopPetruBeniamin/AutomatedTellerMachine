#include "Tests/TestDynamicVector.h"
#include "Tests/TestCollection.h"
#include "ATM.h"

int main() {
    testDynamicVector();
    testCollection();

    Collection<int> c1;
    c1.add(1);
    c1.add(1);
    c1.add(1);
    c1.add(1);
    c1.add(5);
    c1.add(5);
    c1.add(5);
    c1.add(5);
    c1.add(5);
    c1.add(5);
    c1.add(10);
    c1.add(10);
    c1.add(10);
    c1.add(10);
    c1.add(20);
    c1.add(20);

    ATM atm(c1);

    atm.runProgram();
    return 0;
}
