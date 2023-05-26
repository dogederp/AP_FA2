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
    bool qualifiedEmployee = false;
    
    if (shelf.isEmpty()) {
        return true;
    }
    if (shelf.isFull()) {
        return true;
    }
    // check of er een qualified employee is
    for (unsigned int i = 0; i < employees.size(); i++) {
        if (employees[i].getForkliftCertificate() == true) {
            if (employees[i].getBusy() == false) {
                employees[i].setBusy(true);
                qualifiedEmployee = true;
            }
        }
    }
    if (qualifiedEmployee == false) {
        return false;
    }
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
    // neem aantal items van pallet af, zolang er nog items nodig zijn en er nog pallets zijn met items
    // als er geen pallets meer zijn met items, return false
    // als er nog items nodig zijn, return false
    // als er geen items meer nodig zijn, return true
    bool itemsNeeded = true;
    bool pallet = true;
    int itemsTaken = 0;
    for (unsigned int i = 0; i < shelves.size(); i++) {
        for (unsigned int j = 0; j < shelves[i].pallets.size(); j++) {
            pallet = true;
            if (shelves[i].pallets[j].getItemName() == itemName) {
                while (itemsNeeded == true && pallet == true) {
                    if (shelves[i].pallets[j].getItemCount() > 0) {
                        shelves[i].pallets[j].takeOne();
                        itemsTaken++;
                        itemCount--;
                    }
                    if (shelves[i].pallets[j].getItemCount() == 0) {
                        pallet = false;
                    }
                    if (itemCount == 0) {
                        itemsNeeded = false;
                    }
                }
            }
        }
    }
    if (itemCount == 0) {
        return true;
    }
    else {
        std::cout << "Total maximum items taken: " << itemsTaken << std::endl;
        return false;
    }
}
