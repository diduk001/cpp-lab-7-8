cmake_minimum_required(VERSION 3.27)
project(cpp_lab_7_8)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp_lab_7_8 main.cpp
        AbstractBankAccount.h
        CheckingAccount.h
        SavingsAccount.h)
