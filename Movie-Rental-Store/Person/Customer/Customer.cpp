#include "Customer.h"

/******************************************************************************************
 * Customer class implementation
 *****************************************************************************************/

Customer::Customer() {
    mId = mIdCounter++;
    mName = "";
    mAddress = "";
    mNumOfRentedMovies = 0;
};

Customer::~Customer() {};

void Customer::setNumOfRentedMovies(unsigned int numOfRentedMovies) {
    mNumOfRentedMovies = numOfRentedMovies;
}

unsigned int Customer::getNumOfRentedMovies() const {
    return mNumOfRentedMovies;
}

/**
 * @param movie The movie to push to the rental stack.
 * @note This function is used to push a movie to the rental stack.
 */
void Customer::pushRental(unsigned int movieId) {
    mRentedMoviesId.push(movieId);
    mNumOfRentedMovies++;   
}

unsigned int Customer::popRental() {
    unsigned int removedMovieId = mRentedMoviesId.top();

    mRentedMoviesId.pop();
    mNumOfRentedMovies--;

    return removedMovieId;
}

bool Customer::operator==(unsigned int id) const {
    return mId == id;
}
/*****************************************************************************************/


/******************************************************************************************
 * CustomerQueue class implementation
 *****************************************************************************************/

CustomerQueue::CustomerQueue() {
    mSize = 0;
}

CustomerQueue::~CustomerQueue() {}

/**
 * @param customer The customer to enqueue.
 * @note This function is used to enqueue a customer to the queue.
 */
void CustomerQueue::enqueue(Customer customer) {
    mCustomers.push(customer);
    mSize++;
}

/**
 * @note This function is used to dequeue a customer from the queue.
 */
void CustomerQueue::dequeue() {
    mCustomers.pop();
    mSize--;
}

/**
 * @return The customer at the front of the queue.
 * @note This function is used to get the customer at the front of the queue.
 */
Customer CustomerQueue::getFront() const {
    return mCustomers.front();
}

/**
 * @return The customer at the back of the queue.
 * @note This function is used to get the customer at the back of the queue.
 */
Customer CustomerQueue::getBack() const {
    return mCustomers.back();
}

/**
 * @param id The id of the customer to search for.
 * @return A pointer to the customer if found, nullptr otherwise.
 * @note This function is used to search for a customer in the queue.
 */
Customer* CustomerQueue::searchCustomer(unsigned int id) const {
    std::queue<Customer> tempQueue = mCustomers;
    Customer* customer = nullptr;

    while (!tempQueue.empty()) {
        if (tempQueue.front() == id) {
            customer = new Customer(tempQueue.front());
            break;
        }

        tempQueue.pop();
    }

    return customer;
}

/**
 * @return True if the queue is empty, false otherwise.
 * @note This function is used to check if the queue is empty.
 */
bool CustomerQueue::isEmpty() const {
    return mCustomers.empty();
}

/**
 * @return The size of the queue.
 * @note This function is used to get the size of the queue.
 */
unsigned int CustomerQueue::getSize() const {
	return mSize;
}