#include <iostream>
#include <vector>
#include <string>

#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/warehouse.hpp"

Warehouse::Warehouse() {
    this->employees = employees;
    this->shelves = shelves;
}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    if (shelf.isEmpty()) {
        return true;
    }
    if (shelf.isFull()) {
        return true;
    }
    // TODO: check of werknemer die rearranget qualified is en check if werknemer busy is
    for (unsigned int i = 0; i < shelf.pallets.size(); i++) {
        for (unsigned int j = 0; j < shelf.pallets.size() - 1; j++) {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                shelf.swapPallet(j, j + 1);
            }
        }
    }
    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    for (unsigned int i = 0; i < shelves.size(); i++) {
        for (unsigned int j = 0; j < shelves[i].pallets.size(); j++) {
            if (shelves[i].pallets[j].getItemName() == itemName) {
                if (shelves[i].pallets[j].getItemCount() >= itemCount) {
                    for (int k = 0; k < itemCount; k++) {
                        shelves[i].pallets[j].takeOne();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}