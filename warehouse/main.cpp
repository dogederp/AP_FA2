#include <iostream>
#include <string>
#include <vector>

#include "src/include/employee.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"




int main(void){
    Warehouse karloInc = Warehouse();
        std::cout << "Welkom bij karloInc!" << std::endl;

    Shelf s = Shelf();
    s.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Manga", 100, 40), 
        Pallet("Hopes", 100, 30), 
        Pallet("Dreams", 100, 10)
    };
    karloInc.addShelf(s);
    Shelf s2 = Shelf();
    s2.pallets = {
        Pallet("Books", 100, 5), 
        Pallet("Manga", 100, 21), 
        Pallet("Hopes", 100, 50), 
        Pallet("Dreams", 100, 100)
    };
    karloInc.addShelf(s2);
    Shelf s3 = Shelf();
    s3.pallets = {
        Pallet("Books", 100, 100), 
        Pallet("Manga", 100, 69), 
        Pallet("Hopes", 420, 420), 
        Pallet("Dreams", 100, 69)
    };
    karloInc.addShelf(s3);


    Employee e("Karlo", true);
    Employee e2("Doge", false);

    karloInc.addEmployee(e);
    karloInc.addEmployee(e2);

    std::cout << e.getName() << " staat ingeschreven in het warenhuis."<< std::endl;
    std::cout << e2.getName() << " is aanwezig voor mental support."<< std::endl;
    
    std::cout << "Er zijn " << karloInc.employees.size() << " werknemers aanwezig totaal." << std::endl;
    std::cout << "Er zijn " << karloInc.shelves.size() << " schappen aanwezig." << std::endl;

    std::cout << "Voordat shelf 3 gesorteerd wordt: " << karloInc.shelves[2].pallets[0].getItemCount() << " "<< karloInc.shelves[2].pallets[0].getItemName() << std::endl
    << karloInc.shelves[2].pallets[1].getItemCount() << " "<< karloInc.shelves[2].pallets[1].getItemName() << std::endl
    << karloInc.shelves[2].pallets[2].getItemCount() << " "<< karloInc.shelves[2].pallets[2].getItemName() << std::endl
    << karloInc.shelves[2].pallets[3].getItemCount() << " "<< karloInc.shelves[2].pallets[3].getItemName() << std::endl;

    karloInc.rearrangeShelf(karloInc.shelves[2]);

    std::cout << "Na het sorteren van shelf 3: " << karloInc.shelves[2].pallets[0].getItemCount() << " "<< karloInc.shelves[2].pallets[0].getItemName() << std::endl
    << karloInc.shelves[2].pallets[1].getItemCount() << " "<< karloInc.shelves[2].pallets[1].getItemName() << std::endl
    << karloInc.shelves[2].pallets[2].getItemCount() << " "<< karloInc.shelves[2].pallets[2].getItemName() << std::endl
    << karloInc.shelves[2].pallets[3].getItemCount() << " "<< karloInc.shelves[2].pallets[3].getItemName() << std::endl;

    std::cout << "We nemen wat hopes, hebben we wel nodig" << std::endl;

    karloInc.pickItems("Hopes", 420);

    // std::cout << "Na het nemen van de hopes: " << karloInc.shelves[2].pallets[0].getItemCount() << " "<< karloInc.shelves[2].pallets[0].getItemName() << std::endl;
    for (unsigned int i = 0; i < karloInc.shelves[2].pallets.size(); i++){
        // print aantal hopes
        if (karloInc.shelves[2].pallets[i].getItemName() == "Hopes"){
            std::cout << "Na het nemen van de hopes: " << karloInc.shelves[2].pallets[i].getItemCount() << " "<< karloInc.shelves[2].pallets[i].getItemName() << std::endl;
        }
    }

    karloInc.rearrangeShelf(karloInc.shelves[2]);
}
