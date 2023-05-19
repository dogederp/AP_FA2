#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "employee.hpp"
#include "shelf.hpp"

class Warehouse {
    public:
        std::vector<Employee> Employees;
        std::vector<Shelf> Shelves;
        
        Warehouse();
        void addEmployee(Employee Employee);
        void addShelf(Shelf Shelf);
        bool rearrangeShelf(Shelf& Shelf);
        bool pickItems(std::string itemName, int itemCount);
};
