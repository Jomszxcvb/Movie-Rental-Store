#pragma once

#include <stack>
#include <queue>

#include "../Person.h"

class Customer : public Person {
private:
    unsigned int mNumOfRentedMovies;
    std::stack<unsigned int> mRentedMoviesId;

public:
    Customer();
    ~Customer();

    void setNumOfRentedMovies(unsigned int numOfRentedMovies);

    unsigned int getNumOfRentedMovies() const;

    void pushRental(unsigned int movieId);
    unsigned int popRental();


    bool operator==(unsigned int id) const;
};

class CustomerQueue {
private:
    std::queue<Customer> mCustomers;

    unsigned int mSize;

public:
    CustomerQueue();
    ~CustomerQueue();

    void enqueue(Customer customer);
    void dequeue();

    Customer getFront() const;
    Customer getBack() const;

    Customer* searchCustomer(unsigned int id) const;

    bool isEmpty() const;
    unsigned int getSize() const;
};

