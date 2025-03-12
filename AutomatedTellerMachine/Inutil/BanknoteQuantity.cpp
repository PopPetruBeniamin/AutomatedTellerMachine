#include "BanknoteQuantity.h"

BanknoteQuantity::BanknoteQuantity() {
    banknote = 0;
    quantity = 0;
}

BanknoteQuantity::BanknoteQuantity(int givenBanknote, int givenQuantity) {
    banknote = givenBanknote;
    quantity = givenQuantity;
}

BanknoteQuantity::BanknoteQuantity(const BanknoteQuantity& givenBanknoteQuantity) {
    this->banknote = givenBanknoteQuantity.banknote;
    this->quantity = givenBanknoteQuantity.quantity;
}

BanknoteQuantity::~BanknoteQuantity()= default;


void BanknoteQuantity::setBanknote(int givenBanknote) {
    banknote = givenBanknote;
}

void BanknoteQuantity::setQuantity(int givenQuantity) {
    quantity = givenQuantity;
}

int BanknoteQuantity::getBanknote() const {
    return this->banknote;
}

int BanknoteQuantity::getQuantity() const {
    return this->quantity;
}

bool BanknoteQuantity::operator<(const BanknoteQuantity& givenBanknoteQuantity) const {
    return (this->banknote < givenBanknoteQuantity.banknote);
}


bool BanknoteQuantity::operator>(const BanknoteQuantity& givenBanknoteQuantity) const {
    return (this->banknote > givenBanknoteQuantity.banknote);
}

bool BanknoteQuantity::operator<=(const BanknoteQuantity& givenBanknoteQuantity) const {
    return (this->banknote <= givenBanknoteQuantity.banknote);
}

bool BanknoteQuantity::operator>=(const BanknoteQuantity& givenBanknoteQuantity) const {
    return (this->banknote >= givenBanknoteQuantity.banknote);
}

bool BanknoteQuantity::operator==(const BanknoteQuantity& givenBanknoteQuantity) const {
    return ((this->banknote == givenBanknoteQuantity.banknote) && (this->quantity == givenBanknoteQuantity.quantity));
}

BanknoteQuantity& BanknoteQuantity::operator=(const BanknoteQuantity& givenBanknoteQuantity) {
    if(this != &givenBanknoteQuantity){
        this->banknote = givenBanknoteQuantity.banknote;
        this->quantity = givenBanknoteQuantity.quantity;
    }
    return *this;
}
