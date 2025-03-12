#ifndef SD_LAB2_BANKNOTEQUANTITY_H
#define SD_LAB2_BANKNOTEQUANTITY_H

class BanknoteQuantity{
private:
    int banknote;
    int quantity;

public:

    BanknoteQuantity();
    BanknoteQuantity(int givenBanknote, int givenQuantity);
    BanknoteQuantity(const BanknoteQuantity&);
    ~BanknoteQuantity();

    //Seteri
    void setBanknote(int givenBanknote);
    void setQuantity(int givenQuantity);

    //Geteri
    [[nodiscard]] int getBanknote() const;
    [[nodiscard]] int getQuantity() const;

    bool operator<(const BanknoteQuantity &) const;
    bool operator>(const BanknoteQuantity &) const;
    bool operator<=(const BanknoteQuantity &) const;
    bool operator>=(const BanknoteQuantity &) const;
    bool operator==(const BanknoteQuantity &) const;

    BanknoteQuantity& operator=(const BanknoteQuantity &);
};
#endif //SD_LAB2_BANKNOTEQUANTITY_H
