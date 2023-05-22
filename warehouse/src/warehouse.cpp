#pragma once
#include <iostream>
#include <vector>

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
        return false;
    }
    for (int i = 0; i < shelf.pallets.size(); i++) {
        if (shelf.pallets[i].isEmpty()) {
            for (int j = i + 1; j < shelf.pallets.size(); j++) {
                if (!shelf.pallets[j].isEmpty()) {
                    shelf.swapPallet(i, j);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    for (int i = 0; i < shelves.size(); i++) {
        for (int j = 0; j < shelves[i].pallets.size(); j++) {
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