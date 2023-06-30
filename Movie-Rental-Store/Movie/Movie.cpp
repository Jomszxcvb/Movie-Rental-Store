#include "Movie.h"

/******************************************************************************************
 * Movie class implementation
 *****************************************************************************************/

 /**
  * @brief Static member variable to keep track of the number of movies.
  * @note This variable is initialized to 1, because the first movie will have an id of 1.
  *       This is because the id is incremented after it is assigned to the movie.
  *       So the first movie will have an id of 1, the second movie will have an id of 2, etc.
  **/
unsigned int Movie::mIdCounter = 1;
Movie::Movie() {
    mId = mIdCounter++;
    mTitle = "";
    mGenre = "";
    mProduction = "";
    mNumOfCopies = 0;
    mImgFilename = "";
}
Movie::~Movie() {}

void Movie::setId(unsigned int id) { mId = id; }
void Movie::setTitle(std::string title) { mTitle = title; }
void Movie::setGenre(std::string genre) { mGenre = genre; }
void Movie::setProduction(std::string production) { mProduction = production; }
void Movie::setNumOfCopies(unsigned int numOfCopies) { mNumOfCopies = numOfCopies; }
void Movie::setImgFilename(std::string imgFilename) { mImgFilename = imgFilename; }

void Movie::increaseNumOfCopies() { mNumOfCopies++; }
void Movie::decreaseNumOfCopies() { mNumOfCopies--; }

void Movie::setNext(Movie* next) { mNext = next; }

unsigned int Movie::getId() { return mId; }
std::string Movie::getTitle() { return mTitle; }
std::string Movie::getGenre() { return mGenre; }
std::string Movie::getProduction() { return mProduction; }
unsigned int Movie::getNumOfCopies() { return mNumOfCopies; }
std::string Movie::getImgFilename() { return mImgFilename; }

Movie* Movie::getNext() { return mNext; }

/**
 * @brief Overloaded operator to compare two Movie objects.
 * @param Movie The Movie object to compare with.
 * @return True if the two Movie objects are the same, false otherwise.
 **/
bool Movie::operator==(unsigned int id) const {
    return mId == id;
}
/*****************************************************************************************/
//
//
//
/******************************************************************************************
 * MovieLibrary class implementation
 *****************************************************************************************/

MovieLibrary::MovieLibrary() {
    mHead = nullptr;
    mTail = nullptr;

    mSize = 0;
}

MovieLibrary::~MovieLibrary() {
    Movie *current = mHead;
    Movie *next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        delete current;
        current = next;
    }
}

/**
 * @brief Inserts a movie into the movie library.
 * @param movie The movie to insert.
 * @note The movie is inserted at the end of the list.
 **/
void MovieLibrary::insert(Movie movie) {
    Movie *newMovie = new Movie();
    *newMovie = movie;

    if (mHead == nullptr) {
        mHead = newMovie;
        mTail = newMovie;
    } else {
        mTail->setNext(newMovie);
        mTail = newMovie;
    }

    mSize++;
}

/**
 * @brief Removes a movie from the movie library.
 * @param id The id of the movie to remove.
 * @note If the movie is not found, nothing happens.
 **/
void MovieLibrary::remove(unsigned int id) {
    Movie *current = mHead;
    Movie *previous = nullptr;

    while (current != nullptr) {
        if (*current == id) {
            if (current == mHead) {
                mHead = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }

            if (current == mTail) {
                mTail = previous;
            }

            delete current;
            mSize--;
            break;
        }

        previous = current;
        current = current->getNext();
    }
}

/**
 * @brief Searches for a movie in the movie library.
 * @param id The id of the movie to search for.
 * @return A pointer to the movie if it is found, nullptr otherwise.
 **/
Movie *MovieLibrary::searchMovie(unsigned int id) const {
    Movie *current = mHead;

    while (current != nullptr) {
        if (*current == id) {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
}

Movie *MovieLibrary::getHead() const { return mHead; }

bool MovieLibrary::isEmpty() const { return mHead == nullptr; }

unsigned int MovieLibrary::getSize() const { return mSize; }

/*****************************************************************************************/
