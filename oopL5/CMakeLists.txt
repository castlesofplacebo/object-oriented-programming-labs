cmake_minimum_required(VERSION 3.17)
project(oopL5)

set(CMAKE_CXX_STANDARD 17)

add_executable(oopL5 main.cpp ClientDecorator.cpp ClientDecorator.h Client.cpp Client.h Bank.cpp Bank.h BankAccount.cpp BankAccount.h DebitBankAccount.cpp DebitBankAccount.h CreditBankAccount.cpp CreditBankAccount.h DepositBankAccount.cpp DepositBankAccount.h AbstractClient.cpp AbstractClient.h ClientAddress.cpp ClientAddress.h ClientPassport.cpp ClientPassport.h)