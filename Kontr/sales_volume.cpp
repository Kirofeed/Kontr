#include "sales_volume.h"

SalesVolume::SalesVolume(const std::string& title, Genre genre, int year, int actualStores)
    : LiteratureWork(title, genre, year), actualStores(actualStores) {
    for (size_t i = 0; i < maxStores; i++)
    {
        Sales[i] = 0;
    }
}

SalesVolume::SalesVolume(const SalesVolume& other)
    : LiteratureWork(other), actualStores(other.actualStores), Sales(other.Sales) {}

SalesVolume& SalesVolume::operator=(const SalesVolume& other) {
    if (this != &other) {
        LiteratureWork::operator=(other);
        actualStores = other.actualStores;
        Sales = other.Sales;
    }
    return *this;
}

SalesVolume::SalesVolume(SalesVolume&& other) : LiteratureWork(other), actualStores(other.actualStores), Sales(Sales) {}


SalesVolume& SalesVolume::operator=(SalesVolume&& other) {
    if (this != &other) {
        title = std::move(other.title);
        year = other.year;
        actualStores = other.actualStores;
        Sales = other.Sales;
    }
    return *this;
}


SalesVolume::~SalesVolume() {}

void SalesVolume::setActualStores(int stores) {
    if (stores > maxStores) {
        throw std::invalid_argument("Actual stores cannot exceed max stores.");
    }
    actualStores = stores;
}

int SalesVolume::getActualStores() const {
    return actualStores;
}

void SalesVolume::setSales(int Shop, int Num_OfSold) {
    this->Sales[Shop] = Num_OfSold;
}

int* SalesVolume::getSales() const {
    return Sales;
}

std::ostream& operator<<(std::ostream& os, const SalesVolume& volume) {
    os << static_cast<const LiteratureWork&>(volume) << ", Max Stores: " << volume.maxStores << ", Actual Stores: " << volume.actualStores;
    os << ", Sales: [";
    if (volume.maxStores > 1)
    {
        os << volume.Sales[0];
        for (int i = 1; i < volume.maxStores; ++i) {
            os << ", " << volume.Sales[i];
        }
    }
    else if (volume.maxStores == 1)
    {
        os << volume.Sales[0] << ", ";
    }
    
    os << "]";
    return os;
}
