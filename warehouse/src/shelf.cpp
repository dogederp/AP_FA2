#include <iostream>

#include "include/shelf.hpp"

Shelf::Shelf(){
    this->pallets = pallets;
}

bool Shelf::swapPallet(int slot, int slot2){
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
}

bool Shelf::isEmpty() {
    for (int i = 0; i < pallets.size(); i++) {
        if (!pallets[i].isEmpty()) {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull() {
    for (int i = 0; i < pallets.size(); i++) {
        if (!pallets[i].isFull()) {
            return false;
        }
    }
    return true;
}