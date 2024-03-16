#include <iostream>
#include "literature.h"
#include "sales_volume.h"

int main() {
    // Создание объектов класса "Литературное произведение"
    LiteratureWork literature1("war and piece", ROMAN, 1869);
    LiteratureWork literature2("master i margarita", ROMAN, 1967);
    LiteratureWork literature3("evgeni onegin", POEMA, 1833);



     //Создание объектов класса "Объем продаж"
    SalesVolume sales1("war and piece", ROMAN, 1869, 4);
    SalesVolume sales2("master i margarita", ROMAN, 1967, 4);


    sales1 = std::move(sales2);
    std::cout << sales1 << std::endl;

     //Установка данных для объекта "Объем продаж"
  

    // Вывод информации о созданных объектах
    std::cout << "Information about literature:\n";
    std::cout << literature1 << std::endl;
    std::cout << literature2 << std::endl;
    std::cout << literature3 << std::endl;

    std::cout << "\nInformation about SellingVolue:\n";
    std::cout << sales1 << std::endl;
    std::cout << sales2 << std::endl;

    // Сравнение объектов класса "Литературное произведение" по жанру
    if (literature1 == literature2) {
        std::cout << "atr of one type\n";
    }
    else {
        std::cout << "atr of different type\n";
    }

    // Сравнение объектов разных классов
    if (literature1 == sales1) {
        std::cout << "obj of one class\n";
    }
    else {
        std::cout << "obj of different class\n";
    }



    LiteratureWork* array[5];


    array[0] = &literature1;
    array[1] = &literature2;
    array[2] = &literature3;
    array[3] = &sales1;
    array[4] = &sales2;

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << *array[i] << std::endl << std::endl << std::endl;
    }
























    return 0;
}
        