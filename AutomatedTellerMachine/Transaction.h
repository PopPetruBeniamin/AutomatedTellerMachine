#ifndef SD_LAB2_TRANSACTION_H
#define SD_LAB2_TRANSACTION_H

#include <iostream>
#include "DynamicVector.h"

using namespace std;

class Transaction{
private:
    static int counter;
    int id;
    int sum;
    DynamicVector<int> banknotes;

public:
    Transaction();
    Transaction(int givenSum, const DynamicVector<int>& givenBanknotes);
    Transaction(const Transaction& givenTransaction);
    ~Transaction();

    friend ostream& operator<<(ostream& os, Transaction& t);
};
#endif //SD_LAB2_TRANSACTION_H
