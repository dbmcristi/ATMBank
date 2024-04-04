cmake_minimum_required(VERSION 3.24)
project(ATMBank)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATMBank main.cpp atm/ATM.cpp atm/ATM.h transaction/Transaction.cpp transaction/Transaction.h collection/Collection.cpp collection/Collection.h Consola/Consola.cpp Consola/Consola.h)
