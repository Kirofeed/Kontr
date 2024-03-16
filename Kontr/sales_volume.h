#pragma once
#ifndef SALES_VOLUME_H
#define SALES_VOLUME_H

#include <iostream>
#include <vector>
#include "literature.h"

class SalesVolume : public LiteratureWork {
private:
    const int maxStores = 10;
    int actualStores;
    int* Sales = new int[maxStores];

public:
    SalesVolume(const std::string& title, Genre genre, int year, int actualStores);
    SalesVolume(const SalesVolume& other);
    SalesVolume(SalesVolume&& other);
    SalesVolume& operator=(const SalesVolume& other);
    SalesVolume& operator=(SalesVolume&& other);
    ~SalesVolume();

    void setActualStores(int stores);
    int getActualStores() const;
    void setSales(int Shop, int Num_OfSold);
    int* getSales() const;

    friend std::ostream& operator<<(std::ostream& os, const SalesVolume& volume);
};

#endif // SALES_VOLUME_H
