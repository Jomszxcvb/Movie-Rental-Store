#include "Helper/FileHandler.h"
#include <map>
#include <iostream>

#include "Helper/StoreHelper.h"
#include "Movie/Movie.h"
#include "Person/Customer/Customer.h"

int main() {
	FileHandler fileHandler;
	CustomerQueue customerQueue = fileHandler.readCustomersFromFile();
	MovieLibrary movieLibrary = fileHandler.readMoviesFromFile();


	while (true) {
		MAIN_MENU:
		displayMainMenu();
		switch (promptInt("Enter choice: ")) {
		case 1: {/*TODO : PROGRAMMER 1*/} break;
		case 2: {
			displayHeader("RENT A MOVIE");

			int customerId = promptInt("Enter customer ID: ");
			Customer* customer = customerQueue.searchCustomer(customerId);
			if (customer == nullptr) {
				std::cout << "Customer not found!" << std::endl;
				continue;
			}

			displayTable(std::vector<std::string>{"Name: ", customer->getName()}, 
				std::vector<std::vector<std::string>>{ {"Address: ", customer->getAddress()} });

			std::cout << "Movies To Rent..." << std::endl;

			while (true) {
				std::cout << "Enter video ID: ";
				int movieId = promptInt("");
				Movie* movie = movieLibrary.searchMovie(movieId);
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
				displayTable({ "Movie Title: ", movie->getTitle() },
					{ { "Number of Copies: ", std::to_string(movie->getNumOfCopies()) }});

				while (true) {
					char choice = promptChar("Rent another movie? (Y/N): ");
					if (choice == 'Y' || choice == 'y') { break; }
					else if (choice == 'N' || choice == 'n') { goto MAIN_MENU; }
					else { continue; }
				}
			}
			break;
		}
		case 3: {

			break;
		}
		case 4: {/*TODO : PROGRAMMER 2*/} break;
		case 5: {/*TODO : PROGRAMMER 1*/} break;
		case 6: {/*TODO : PROGRAMMER 2*/} break;
		case 7: {
			while (true) {
				displayCustomerMaintenanceMenu();
				switch (promptInt("Enter choice: ")) {
				case 1: {/*TODO : PROGRAMMER 1*/} break;
				case 2: {/*TODO : PROGRAMMER 2*/} break;
				case 3: {
					displayHeader("LIST OF MOVIES RENTED BY CUSTOMER");

					int customerId = promptInt("Enter customer ID: ");
					Customer* customer = customerQueue.searchCustomer(customerId);
					if (customer == nullptr) {
						std::cout << "Customer not found!" << std::endl;
						continue;
					}
					displayTable(std::vector<std::string>{"Name: ", customer->getName()},
						std::vector<std::vector<std::string>>{ {"Address: ", customer->getAddress()} });

					std::cout << "List Of Videos Rented..." << std::endl;
					std::stack<unsigned int> stackRentedMoviesId = customer->getRentedMoviesId();
					std::map<std::string, std::string> mapRentedMovies;
					if (stackRentedMoviesId.empty()) {
						std::cout << "No movies rented!" << std::endl;
						continue;
					}
					while (!stackRentedMoviesId.empty()) {
						std::map<std::string, std::string> movie;
						movie[std::to_string(stackRentedMoviesId.top())] = movieLibrary.searchMovie(stackRentedMoviesId.top())->getTitle();
						stackRentedMoviesId.pop();
					}
					
					std::vector<std::vector<std::string>> vectRentedMoviesIdTitle;
					for (auto& movie : mapRentedMovies) {
						vectRentedMoviesIdTitle.push_back({ movie.first, movie.second });
					}
					displayTable(std::vector<std::string>{"Video ID", "Video Title"}, vectRentedMoviesIdTitle);

					break;
				}
				default:
					continue;
				}
			}
		} break;
		case 8: {/*TODO : PROGRAMMER 1*/} break;
		default: continue;
		}
	}
	return 0;
}