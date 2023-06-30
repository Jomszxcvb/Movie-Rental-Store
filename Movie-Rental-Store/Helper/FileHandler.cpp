#include "FileHandler.h"


/**
 * @note This function is used to initialize the file handler.
 *       It creates an accounts directory if it does not exist.
 */
FileHandler::FileHandler() {}

FileHandler::~FileHandler() {}

/**
 * @param customers The customer queue to write to the file.
 * @note This function is used to write the customers to the file.
 */
void FileHandler::writeCustomersToFile(CustomerQueue customers) {
    mCustomerDirectory;
    mFile.open(mCustomerDirectory, std::ios::out);

    if (mFile.is_open()) {
        while (!customers.isEmpty()) {
            Customer customer = customers.getFront();
            mFile << customer.getId() << std::endl;
            mFile << customer.getName() << std::endl;
            mFile << customer.getAddress() << std::endl;
            mFile << customer.getNumOfRentedMovies() << std::endl;
            mFile << std::endl;

            customers.dequeue();
        }
    }
    else {
        std::cout << "Unable to access customer accounts..." << std::endl;
    }

    mFile.close();
}

/**
 * @param movies The movie library to write to the file.
 * @note This function is used to write the movies to the file.
 */
void FileHandler::writeMoviesToFile(MovieLibrary movies) {
    mMovieDirectory;
    mFile.open(mMovieDirectory, std::ios::out);

    if (mFile.is_open()) {
        while (!movies.isEmpty()) {
            Movie* movie = movies.getHead();
            mFile << movie->getId() << std::endl;
            mFile << movie->getTitle() << std::endl;
            mFile << movie->getGenre() << std::endl;
            mFile << movie->getProduction() << std::endl;
            mFile << movie->getNumOfCopies() << std::endl;
            mFile << movie->getImgFilename() << std::endl;
            mFile << std::endl;

            movies.remove(movie->getId());
        }
    }
    else {
        std::cout << "Unable to access movie library..." << std::endl;
    }

    mFile.close();
}

/**
 * @return The customer queue read from the file.
 * @note This function is used to read the customers from the file.
 */
CustomerQueue FileHandler::readCustomersFromFile() {
    CustomerQueue customers;

    mCustomerDirectory;
    mFile.open(mCustomerDirectory, std::ios::in);

    if (mFile.is_open()) {
        while (!mFile.eof()) {
            Customer customer;
            std::string line;

            std::getline(mFile, line);
            if (line.empty()) {
                break;
            }
            customer.setId(std::stoi(line));

            std::getline(mFile, line);
            customer.setName(line);

            std::getline(mFile, line);
            customer.setAddress(line);

            std::getline(mFile, line);
            customer.setNumOfRentedMovies(std::stoi(line));

            std::getline(mFile, line);

            customers.enqueue(customer);
        }
    }

    mFile.close();

    return customers;
}

/**
 * @return The movie library read from the file.
 * @note This function is used to read the movies from the file.
 */
MovieLibrary FileHandler::readMoviesFromFile() {
    MovieLibrary movies;

    mMovieDirectory;
    mFile.open(mMovieDirectory, std::ios::in);

    if (mFile.is_open()) {
        while (!mFile.eof()) {
            Movie movie;
            std::string line;

            std::getline(mFile, line);
            if (line.empty()) {
                break;
            }
            movie.setId(std::stoi(line));

            std::getline(mFile, line);
            movie.setTitle(line);

            std::getline(mFile, line);
            movie.setGenre(line);

            std::getline(mFile, line);
            movie.setProduction(line);

            std::getline(mFile, line);
            movie.setNumOfCopies(std::stoi(line));

            std::getline(mFile, line);
            movie.setImgFilename(line);

            std::getline(mFile, line);

            movies.insert(movie);
        }
    }

    mFile.close();

    return movies;
}