#pragma once
#ifndef LITERATURE_H
#define LITERATURE_H

#include <iostream>
#include <string>

enum Genre { ROMAN, POVEST, POEMA, MEMUARY };

class LiteratureWork {
protected:
    const int id;
    std::string title;
    const Genre genre;
    int year;
private:
    static int counter;
public:
    LiteratureWork() = delete;
    LiteratureWork(const std::string& title, Genre genre, int year);
    LiteratureWork(const LiteratureWork& other);
    LiteratureWork(LiteratureWork&& other);
    LiteratureWork& operator=(const LiteratureWork& other);
    LiteratureWork& operator=(LiteratureWork&& other);
    ~LiteratureWork();

    int getId() const;
    std::string getTitle() const;
    Genre getGenre() const;
    int getYear() const;

    friend std::ostream& operator<<(std::ostream& os, const LiteratureWork& work);
    friend bool operator==(const LiteratureWork& work1, const LiteratureWork& work2);
};

#endif // LITERATURE_H
