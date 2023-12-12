//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_USER_H
#define CPP_LAB_7_8_USER_H

#include "CheckingAccount.h"
#include "SavingsAccount.h"

class User {
private:
    std::string name;
    CheckingAccount checkingAccount;
    SavingsAccount savingsAccount;
public:
    // Empty constructor
    User() {
        name = "";
        checkingAccount = CheckingAccount();
        savingsAccount = SavingsAccount();
    }

    // Constructor with initial name
    explicit User(const std::string &name) {
        this->name = name;
        checkingAccount = CheckingAccount();
        savingsAccount = SavingsAccount();
    }

    // Constructor with initial name, checkingAccount and savingsAccount
    User(const std::string &name, const CheckingAccount &checkingAccount, const SavingsAccount &savingsAccount) {
        this->name = name;
        this->checkingAccount = CheckingAccount(checkingAccount);
        this->savingsAccount = SavingsAccount(savingsAccount);
    }

    // Copy constructor
    User(const User &other) {
        name = other.name;
        checkingAccount = CheckingAccount(other.checkingAccount);
        savingsAccount = SavingsAccount(other.savingsAccount);
    }

    // Destructor
    ~User() {
    }

    // Copy assignment operator
    User &operator=(const User &other) {
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

    // Accessors

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

    void setCheckingAccount(const CheckingAccount &newCheckingAccount) {
        checkingAccount = CheckingAccount(newCheckingAccount);
    }

    void setSavingsAccount(const SavingsAccount &newSavingsAccount) {
        savingsAccount = SavingsAccount(newSavingsAccount);
    }

    // Format
    void format(std::ostream &out) const {
        out << "User = { name: \"" << getName() << "\", checkingAccount: " << getCheckingAccount()
            << ", savingsAccount: " << getSavingsAccount() << " }";
    }
};

std::ostream &operator<<(std::ostream &out, const User &user) {
    user.format(out);
    return out;
}


#endif //CPP_LAB_7_8_USER_H
