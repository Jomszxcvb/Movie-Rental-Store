#pragma once

#include <string>

class Movie {
protected:
    unsigned int mId;
    std::string mTitle;
    std::string mGenre;
    std::string mProduction;
    unsigned int mNumOfCopies;
    std::string mImgFilename;

    static unsigned int mIdCounter;

    Movie* mNext;

public:
    Movie();
    ~Movie();

    void setId(unsigned int id);
    void setTitle(std::string title);
    void setGenre(std::string genre);
    void setProduction(std::string production);
    void setNumOfCopies(unsigned int numOfCopies);
    void setImgFilename(std::string imgFilename);
    void setNext(Movie* next);

    unsigned int getId();
    std::string getTitle();
    std::string getGenre();
    std::string getProduction();
    unsigned int getNumOfCopies();
    std::string getImgFilename();
    Movie* getNext();

    void increaseNumOfCopies();
    void decreaseNumOfCopies();

    bool operator==(unsigned int id) const;
};

class MovieLibrary {
private:
    Movie* mHead;
    Movie* mTail;

    unsigned int mSize;

public:
    MovieLibrary();
    ~MovieLibrary();

    void insert(Movie movie);
    void remove(unsigned int id);
    Movie* searchMovie(unsigned int id) const;

    Movie* getHead() const;

    bool isEmpty() const;
    unsigned int getSize() const;
};

