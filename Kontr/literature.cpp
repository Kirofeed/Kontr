#include "literature.h"
#include <iostream>

LiteratureWork::LiteratureWork(const std::string& title, Genre genre, int year) : 
    title(title), genre(genre), year(year), id(counter++) {}

LiteratureWork::LiteratureWork(const LiteratureWork& other)
    : id(other.id), title(other.title), genre(other.genre), year(other.year) {}


LiteratureWork::LiteratureWork(LiteratureWork&& other) : title(std::move(other.title)), genre(other.genre), year(other.year), id(counter++) {}

LiteratureWork& LiteratureWork::operator=(const LiteratureWork& other) {
    if (this != &other) {
        title = other.title;
        year = other.year;
    }
    return *this;
}

LiteratureWork& LiteratureWork::operator=(LiteratureWork&& other) {
    if (this != &other) {
        title = std::move(other.title);
        year = other.year;
    }
    return *this;
}

//bool LiteratureWork::operator==(const LiteratureWork& other) const {
//    if (this->genre == other.genre) {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

LiteratureWork::~LiteratureWork() {}

int LiteratureWork::counter = 1;

int LiteratureWork::getId() const {
    return id;
}

std::string LiteratureWork::getTitle() const {
    return title;
}

Genre LiteratureWork::getGenre() const {
    return genre;
}

int LiteratureWork::getYear() const {
    return year;
}

std::ostream& operator<<(std::ostream& os, const LiteratureWork& work) {
    os << "ID: " << work.id << ", Title: " << work.title << ", Genre: " << work.genre << ", Year: " << work.year;
    return os;
}

bool operator==(const LiteratureWork& work1, const LiteratureWork& work2) {
    return (work1.genre == work2.genre);
}
