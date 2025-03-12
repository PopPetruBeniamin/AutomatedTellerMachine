//
// Created by Usuario on 30/04/2024.
//

#include "Transaction.h"

int Transaction::counter = 0;

Transaction::Transaction() {
    this->id = 0;
    this-> sum = 0;
    this->banknotes = DynamicVector<int>();
}

Transaction::Transaction(int givenSum, const DynamicVector<int>& givenBanknotes) {
    this->id = ++counter;
    this-> sum = givenSum;
    this->banknotes = givenBanknotes;
}

Transaction::Transaction(const Transaction& givenTransaction) {
    this->id = givenTransaction.id;
    this->sum = givenTransaction.sum;
    this->banknotes = givenTransaction.banknotes;
}

ostream &operator<<(ostream &os, Transaction &t) {
    cout << "============Transaction============\n";
    cout << "Id: " << t.id << endl;
    cout << "Sum: " << t.sum << endl;
    cout << "Banknotes: ";
    for(int i = 0 ; i < t.banknotes.size() ; i++)
        cout << t.banknotes.getAt(i) << "$ ";
    cout << endl;
    return os;
}


Transaction::~Transaction() = default;
