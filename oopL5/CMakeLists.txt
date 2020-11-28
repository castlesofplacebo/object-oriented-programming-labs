cmake_minimum_required(VERSION 3.17)
project(oopL5)

set(CMAKE_CXX_STANDARD 17)

add_executable(oopL5 main.cpp Client.cpp Client.h Bank.cpp Bank.h BankAccount.cpp BankAccount.h DebitBankAccount.cpp DebitBankAccount.h CreditBankAccount.cpp CreditBankAccount.h DepositBankAccount.cpp DepositBankAccount.h Builder.cpp Builder.h ClientBuilder.cpp ClientBuilder.h)