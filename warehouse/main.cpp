#include <iostream>
#include <string>
#include <vector>

#include "src/include/employee.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"




int main(void){
    Employee e("Karlo", true);
    std::cout << e.getName();
    std::cout << "Hello world" << std::endl;
}
