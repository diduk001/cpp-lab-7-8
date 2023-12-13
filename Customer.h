//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_CUSTOMER_H
#define CPP_LAB_7_8_CUSTOMER_H

#include "CheckingAccount.h"
#include "SavingsAccount.h"

class Customer {
private:
    std::string name;
    CheckingAccount checkingAccount;
    SavingsAccount savingsAccount;
public:
    // Empty constructor
    Customer() {
        name = "";
        checkingAccount = CheckingAccount();
        savingsAccount = SavingsAccount();
    }

    // Constructor with initial name
    explicit Customer(const std::string &name) {
        this->name = name;
        checkingAccount = CheckingAccount();
        savingsAccount = SavingsAccount();
    }

    // Constructor with initial name, checkingAccount and savingsAccount
    Customer(const std::string &name, const CheckingAccount &checkingAccount, const SavingsAccount &savingsAccount) {
        this->name = name;
        this->checkingAccount = CheckingAccount(checkingAccount);
        this->savingsAccount = SavingsAccount(savingsAccount);
    }

    // Copy constructor
    Customer(const Customer &other) {
        name = other.name;
        checkingAccount = CheckingAccount(other.checkingAccount);
        savingsAccount = SavingsAccount(other.savingsAccount);
    }

    // Destructor
    ~Customer() {
    }

    // Copy assignment operator
    Customer &operator=(const Customer &other) {
        if (this != &other) {
            name = other.name;
            checkingAccount = CheckingAccount(other.checkingAccount);
            savingsAccount = SavingsAccount(other.savingsAccount);
        }
        return *this;
    }

    // Getters
    std::string getName() const {
        return name;
    }

    CheckingAccount getCheckingAccount() const {
        return checkingAccount;
    }

    SavingsAccount getSavingsAccount() const {
        return savingsAccount;
    }

    // Account accessors

    CheckingAccount &accessCheckingAccount() {
        return checkingAccount;
    }

    SavingsAccount &accessSavingsAccount() {
        return savingsAccount;
    }

    // Setters
    void setName(const std::string &newName) {
        name = newName;
    }

    // Format
    void format(std::ostream &out) const {
        out << "Customer = { name: \"" << getName() << "\" , checkingAccount: " << getCheckingAccount()
            << ", savingsAccount: " << getSavingsAccount() << " }";
    }

    friend std::istream &operator>>(std::istream &in, Customer &user);

    friend std::ostream &operator<<(std::ostream &out, const Customer &user) {
        user.format(out);
        return out;
    }
};


#endif //CPP_LAB_7_8_CUSTOMER_H
