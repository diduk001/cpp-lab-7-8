cmake_minimum_required(VERSION 3.27)
project(cpp_lab_7_8)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp_lab_7_8 main.cpp
        BankAccount.h
        BankAccount.cpp
        StreamUtils.h
        CheckingAccount.h
        CheckingAccount.cpp
        SavingsAccount.h
        SavingsAccount.cpp
        Transaction.h
        Customer.h
        StreamUtils.cpp
        Customer.cpp
        Transaction.cpp
)
