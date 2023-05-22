#pragma once
#include <iostream>
#include <string>

#include "include/pallet.hpp"

Pallet::Pallet() {
    this->itemCount = 0;
    this->itemName = "";
    this->itemCapacity = 0;
}

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
    this->itemCount = 0;
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
}

std::string Pallet::getItemName() {
    return this->itemName;
}

// todo: implement functie voor "bool isEmpty() override;"