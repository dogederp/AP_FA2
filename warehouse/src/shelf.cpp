#include "include/shelf.hpp"

Shelf::Shelf(){
    this->pallets = pallets;
}

bool Shelf::swapPallet(int slot, int slot2){
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}

bool Shelf::isEmpty() {
    for (unsigned int i = 0; i < pallets.size(); i++) {
        if (!pallets[i].isEmpty()) {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull() {
    for (unsigned int i = 0; i < pallets.size(); i++) {
        if (!pallets[i].isFull()) {
            return false;
        }
    }
    return true;
}