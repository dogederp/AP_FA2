#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"

#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/warehouse.hpp"

// Find all tests in test*.cpp in test/
// TODO: make testcase for Warehouse::pickItems in testWarehouse
// TODO: Zorg ervoor dat de testcases voor rearrangeShelf werken

// TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
//     // Construct empty warehouse and add empty shelf and forklift certified Employee.
//     Warehouse warehouse = Warehouse();
//     warehouse.addShelf(Shelf());
//     warehouse.addEmployee(Employee("Bob", true));

//     // Rearrange empty shelf
//     REQUIRE(warehouse.rearrangeShelf(warehouse.shelves[0]) == true);
// }