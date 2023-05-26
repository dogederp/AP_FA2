#include <iostream>
#include <vector>
#include <string>

#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/warehouse.hpp"

Warehouse::Warehouse() {
    // default constructor
    this->employees = employees;
    this->shelves = shelves;
}

void Warehouse::addEmployee(Employee employee) {
    // Voeg een employee toe aan de vector van employees
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    // Voeg een shelf toe aan de vector van shelves
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Sorteer de pallets in een shelf op aantal items asc.
    bool qualifiedEmployee = false;
    
    if (shelf.isEmpty()) {
        // als de shelf leeg is, return true, dit telt als gesorteerd
        return true;
    }
    if (shelf.isFull()) {
        // als de shelf vol is, return true, dit telt als gesorteerd
        return true;
    }
    // check of er een qualified employee is
    for (unsigned int i = 0; i < employees.size(); i++) {
        // Check of er iemand met een certificate beschikbaar is
        if (employees[i].getForkliftCertificate() == true && qualifiedEmployee == false) {
            if (employees[i].getBusy() == false) {
                employees[i].setBusy(true);  // Zet geselecteerde employee op busy
                qualifiedEmployee = true;
            }
        }
    }
    if (qualifiedEmployee == false) {
        // Return false als er niemand met een certificate beschikbaar is
        return false;
    }
    for (unsigned int i = 0; i < shelf.pallets.size(); i++) {
        for (unsigned int j = 0; j < shelf.pallets.size() - 1; j++) {
            // Vergelijk pallets met elkaar en sorteer van minst naar meest
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                shelf.swapPallet(j, j + 1);
            }
        }
    }
    // employee hoeft niet meer busy te zijn
    for (unsigned int i = 0; i < employees.size(); i++) {
        if (employees[i].getForkliftCertificate() == true) {
            if (employees[i].getBusy() == true) {
                employees[i].setBusy(false);
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
    int itemsTaken = 0;  // Houd bij hoeveel items er genomen worden
    for (unsigned int i = 0; i < shelves.size(); i++) {
        for (unsigned int j = 0; j < shelves[i].pallets.size(); j++) {
            pallet = true;
            // Neem aantal van gewenste item
            if (shelves[i].pallets[j].getItemName() == itemName) {
                while (itemsNeeded == true && pallet == true) {
                    if (shelves[i].pallets[j].getItemCount() > 0) {
                        shelves[i].pallets[j].takeOne();
                        itemsTaken++;
                        itemCount--;
                    }
                    if (shelves[i].pallets[j].getItemCount() == 0) {
                        // stop als er geen items meer over zijn
                        pallet = false;
                    }
                    if (itemCount == 0) {
                        // geen items meer nodig uit magazijn
                        itemsNeeded = false;
                    }
                }
            }
        }
    }
    if (itemCount == 0) {  // Had ook if (itemsNeeded == false) kunnen zijn
        return true;
    }
    else {
        // Geef aantal items weer die wel gepakt zijn
        std::cout << "Total maximum items taken: " << itemsTaken << std::endl;
        return false;
    }
}
