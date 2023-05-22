#pragma once
#include <iostream>
#include <array>

#include "IContainer.hpp"  //interface
#include "pallet.hpp"  //compositie

class Shelf : public IContainer {
    public:
        std::array <Pallet, 4> pallets;
        
        Shelf();
        bool swapPallet(int slot, int slot2);

        bool isEmpty() override;
        bool isFull() override;
};