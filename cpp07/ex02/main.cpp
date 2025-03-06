#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Boş bir Array oluşturma
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Boyutu 5 olan bir Array oluşturma
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        // Array elemanlarını yazdırma 
        std::cout << "intArray elements: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Kopya constructor'ı test etme
        Array<int> copyArray(intArray);
        std::cout << "copyArray elements: ";
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;

        // Atama operatorünü test etme
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "assignedArray elements: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Hata durumunu test etme
        std::cout << "Accessing out of range element: ";
        std::cout << intArray[10] << std::endl; // Bu satır hata verecek

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
