#include "ATM.h"

//=======================================Constructor=======================================
ATM::ATM(Collection<int> &givenBanknotes) : banknotes(givenBanknotes) {
}

//=======================================Principal functions=======================================
void ATM::displayMenu() {
    cout << "=================Welcome=================\n";
    cout << "1. Display banknotes\n";
    cout << "2. Make withdraw\n";
    cout << "3. Show transactions\n";
    cout << "0. Exit\n";
    cout << "Make a choice: \n";
}

void ATM::displayBanknotes() {
    int currentBanknote;
    for(int i = 0 ; i < banknotes.size() ; i++){
        currentBanknote = banknotes.getAt(i);
        cout << "Banknote: " << currentBanknote << "$ x " << banknotes.nroccurrences(currentBanknote) << endl;
    }
}

void ATM::handlingOption(int givenChoose) {
    switch(givenChoose){
        case 0:
            break;
        case 1:
            displayBanknotes();
            break;
        case 2:
            int sum;
            cout << "Introduce a sum:\n";
            cin >> sum;
            withdraw(sum);
            break;
        case 3:
            displayTransactions();
            break;
        default:
            cout << "Invalid option\n";
            break;
    }
}

void ATM::withdraw(int sum) {
    int counter = 0;
    int option;

    //DV(DynamicVector)
    //Declaration for the DV all combinations,
    DynamicVector<DynamicVector<int>> allCombinations;
    DynamicVector<int> transformed;
    DynamicVector<int> currentCombination;
    DynamicVector<DynamicVector<int>> allCombinationsByASum;

    transformCollectionToVector(this->banknotes, transformed);
    generate_combinations(transformed, 0, counter, currentCombination, allCombinations);

    filterAllCombinationsBySum(sum, allCombinationsByASum, allCombinations);

    if(allCombinationsByASum.size() == 0)
        cout << "There is not enough money to make the withdraw. We are very sorry. Try another sum...\n";
    else{
        for(int i = 0; i < allCombinationsByASum.size(); i++){
                cout << i + 1 << ". ";
                print_vector(allCombinationsByASum[i]);
            }
        cout << "Which one do you want?\n";
        cin >> option;
        while(option < 1 || option > allCombinationsByASum.size()){
            cout << "Invalid option. Choose an option between 1 and " << allCombinationsByASum.size() << endl;
            cin >> option;
        }

        Transaction t(sum, allCombinationsByASum[option - 1]);
        this->transactions.push_back(t);

        for(int i = 0 ; i < allCombinationsByASum[option - 1].size() ; i++)
            this->banknotes.remove(allCombinationsByASum[option - 1][i]);

        cout << "Transaction make successfully\n";
    }
}


//=======================================Complementary Functions=======================================
void ATM::transformCollectionToVector(Collection<int> &c, DynamicVector<int>& transformed) {
    for(int i = 0; i < c.size() ; i++)
        for(int j = 0; j < c.nroccurrences(c.getAt(i)); j++)
            transformed.push_back(c.getAt(i));
}


/*void ATM::generate_combinations(DynamicVector<int>& nums, int start, int& cnt, DynamicVector<int>& combination, DynamicVector<DynamicVector<int>>& deepCopy) {
    deepCopy.push_back(combination);
    cnt++;
    for (int i = start; i < nums.size(); ++i) {
        combination.push_back(nums[i]);
        generate_combinations(nums, i + 1, cnt, combination, deepCopy);
        combination.pop_back();
    }
}*/

void ATM::generate_combinations(DynamicVector<int>& nums, int start, int& cnt, DynamicVector<int>& combination, DynamicVector<DynamicVector<int>>& deepCopy) {
    deepCopy.push_back(combination);
    cnt++;
    for (int i = start; i < nums.size(); ++i) {
        // Evita duplicados continuando desde la última posición
        if (i != start && nums[i] == nums[i - 1]) continue;
        combination.push_back(nums[i]);
        generate_combinations(nums, i + 1, cnt, combination, deepCopy);
        combination.pop_back();
    }
}

void ATM::filterAllCombinationsBySum(int sum, DynamicVector<DynamicVector<int>> &allCombinationsByASum, DynamicVector<DynamicVector<int>> &allCombinations) {
    for(int i = 0; i < allCombinations.size(); i++)
        if(sumElementsVector(allCombinations[i]) == sum){
            allCombinationsByASum.push_back(allCombinations.getAt(i));
        }
}


int ATM::sumElementsVector(DynamicVector<int> &givenVector) {
    int sum = 0;
    for(int i = 0; i < givenVector.size(); i++)
        sum = sum + givenVector[i];
    return sum;
}

void ATM::print_vector(DynamicVector<int>& combination) {
    for (int i = 0; i < combination.size(); ++i) {
        std::cout << combination[i] << " ";
    }
    cout << endl;
}

void ATM::displayTransactions() {
    for(int i = 0; i < this->transactions.size() ; i++)
        cout << this->transactions[i];
}

//=======================================Run Program=======================================
void ATM::runProgram() {
    int choose;
    do{
        displayMenu();
        cin >> choose;
        handlingOption(choose);
    }while(choose);
}

