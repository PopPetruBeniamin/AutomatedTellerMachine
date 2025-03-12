cmake_minimum_required(VERSION 3.27)
project(SD_LAB2)

set(CMAKE_CXX_STANDARD 20)

add_executable(SD_LAB2 main.cpp
        ATM.cpp
        ATM.h
        Collection.h
        DynamicVector.h
        Inutil/BanknoteQuantity.cpp
        Inutil/BanknoteQuantity.h
        Inutil/testBanknoteQuantity.cpp
        Inutil/testBanknoteQuantity.h
        Tests/TestDynamicVector.cpp
        Tests/TestDynamicVector.h
        Tests/TestCollection.cpp
        Tests/TestCollection.h
        Transaction.cpp
        Transaction.h
)
