#pragma once

#include <fstream>
#include <iostream>

#include "../Movie/Movie.h"
#include "../Person/Customer/Customer.h"

class FileHandler {
private:
    const std::string mCustomerDirectory;
    const std::string mMovieDirectory;
    std::fstream mFile;

public:
    FileHandler();
    ~FileHandler();

    void writeCustomersToFile(CustomerQueue customers);
    void writeMoviesToFile(MovieLibrary movies);

    CustomerQueue readCustomersFromFile();
    MovieLibrary readMoviesFromFile();

};

