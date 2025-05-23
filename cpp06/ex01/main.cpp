#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data* data = new Data();
    data->setName("test");
    
    std::cout << "Data* data-> address: " << data << std::endl;
    std::cout << "Data* data->name: " << data->getName() << std::endl;
    
    std::cout << std::endl;
    
    uintptr_t temp = Serializer::serialize(data);
    std::cout << "uintptr_t -> " << temp << std::endl;
    
    std::cout << std::endl;
    
    Data* new_data = Serializer::deserialize(temp);
    std::cout << "Data* new_data-> address: " << new_data << std::endl;
    std::cout << "Data* new_data->name: " << new_data->getName() << std::endl;
    
    std::cout << std::endl;

    if (data == new_data) {
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }

    delete data;
    return 0;
}
