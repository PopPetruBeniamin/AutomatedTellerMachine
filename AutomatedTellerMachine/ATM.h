#ifndef SD_LAB2_ATM_H
#define SD_LAB2_ATM_H

#include <iostream>
#include "Collection.h"
#include "Transaction.h"

using namespace std;
class ATM {
private:
    Collection<int>& banknotes;
    DynamicVector<Transaction> transactions;

public:
    // Constructor
    explicit ATM(Collection<int>& givenBanknotes);
    ~ATM() = default;

    static void transformCollectionToVector(Collection<int>& c, DynamicVector<int>& transformed);
    static void print_vector(DynamicVector<int>& combination);
    void generate_combinations(DynamicVector<int>& nums, int start, int& cnt, DynamicVector<int>& combination, DynamicVector<DynamicVector<int>>& deepCopy);
    static void filterAllCombinationsBySum(int sum, DynamicVector<DynamicVector<int>>& allCombinationsByASum, DynamicVector<DynamicVector<int>>& allCombinations);
    void withdraw(int sum);

    static int sumElementsVector(DynamicVector<int>& givenVector);
    static void displayMenu();
    void displayBanknotes();
    void displayTransactions();
    void runProgram();
    void handlingOption(int givenChoose);
};

#endif //SD_LAB2_ATM_H
