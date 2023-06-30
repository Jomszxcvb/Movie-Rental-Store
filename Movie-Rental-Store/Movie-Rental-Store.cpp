#include "Helper/FileHandler.h"
#include <iostream>

#include "Helper/StoreHelper.h"
#include "Movie/Movie.h"
#include "Person/Customer/Customer.h"

int main() {
    FileHandler fileHandler;
    CustomerQueue customerQueue = fileHandler.readCustomersFromFile();
    MovieLibrary movieLibrary = fileHandler.readMoviesFromFile();


	while (true) {
		displayMainMenu();
		switch (promptInt("Enter choice: ")) {
		case 1: {/*TODO : PROGRAMMER 1*/} break;
		case 2: {/*TODO : LEAD PROGRAMMER*/} break;
		case 3: {/*TODO : LEAD PROGRAMMER*/} break;
		case 4: {/*TODO : PROGRAMMER 2*/} break;
		case 5: {/*TODO : PROGRAMMER 1*/} break;
		case 6: {/*TODO : PROGRAMMER 2*/} break;
		case 7: {
			while (true) {
				displayCustomerMaintenanceMenu();
				switch (promptInt("Enter choice: ")) {
					case 1: {/*TODO : PROGRAMMER 1*/} break;
					case 2: {/*TODO : PROGRAMMER 2*/} break;
					case 3: {/*TODO : LEAD PROGRAMMER*/} break;
					default:
						continue;
				}
			}
		} break;
		case 8: {/*TODO : PROGRAMMER 1*/} break;
		default:
			continue;
		}
	}
    return 0;
}