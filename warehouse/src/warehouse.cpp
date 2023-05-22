#pragma once
#include <iostream>
#include <vector>

#include "employee.hpp"
#include "shelf.hpp"
#include "warehouse.hpp"

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