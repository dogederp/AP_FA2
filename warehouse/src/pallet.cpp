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

int Pallet::getItemCount() {
    return this->itemCount;
}

int Pallet::getRemainingSpace() {
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (this->isEmpty()) {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne() {
    if (!this->isEmpty()) {
        this->itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if (!this->isFull()) {
        this->itemCount++;
        return true;
    }
    return false;
}

bool Pallet::isEmpty() {
    return this->itemCount == 0;
}

bool Pallet::isFull() {
    return this->itemCount == this->itemCapacity;
}
