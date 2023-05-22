#pragma once
#include <iostream>
#include <string>
#include "IContainer.hpp"

class Pallet: public IContainer {
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;

    public:
        Pallet();
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();

        bool isEmpty() override;
};

