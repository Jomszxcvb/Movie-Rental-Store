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
		case 2: {
			displayHeader("RENT A MOVIE");
			int customerId = promptInt("Enter customer ID: ");	
			Customer *customer = customerQueue.searchCustomer(customerId);
			if (customer == nullptr) {
				std::cout << "Customer not found!" << std::endl;
				continue;
			}
			
			///...TODO : display customer info : LEAD PROGRAMMER

			std:: cout << "Movies To Rent..." << std::endl;

			while (true) {
				std::cout << "Enter video ID: ";
				int movieId = promptInt("");

				Movie *movie = movieLibrary.searchMovie(movieId);
				if (movie == nullptr) {
					std::cout << "Movie not found!" << std::endl;
					continue;
				}
				if (movie->getNumOfCopies() == 0) {
					std::cout << "Movie not available!" << std::endl;
					continue;
				}

				movie->decreaseNumOfCopies();	
				customer->pushRental(movie->getId());

				///...TODO : display video info : LEAD PROGRAMMER

				while (true) {
					char choice = promptChar("Rent another movie? (Y/N): ");
					if (choice == 'Y' || choice == 'y') { break; }
					else if (choice == 'N' || choice == 'n') { goto MAIN_MENU; }
					else { continue; }
				}


			}
		} break;
		case 3: {
			displayHeader("RETURN A MOVIE");
			int customerId = promptInt("Enter customer ID: ");
			Customer *customer = customerQueue.searchCustomer(customerId);
			if (customer == nullptr) {
				std::cout << "Customer not found!" << std::endl;
				continue;
			}

			///...TODO : display customer info : LEAD PROGRAMMER

			std::cout << "Movies to Return..." << std::endl;
			
			for (int i = 0; i < customer->getNumOfRentedMovies(); i++) {
				unsigned int customerId = customer->popRental();
				Movie *movie = movieLibrary.searchMovie(customerId);
				movie->increaseNumOfCopies();

				///...TODO : display video info : LEAD PROGRAMMER
			}

			std::cout << "Movies successfully returned!" << std::endl;	
		} break;
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
		MAIN_MENU:
	}
    return 0;
}