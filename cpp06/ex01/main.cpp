#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "HOllY MOLLY";
    original.value = 13.37;

    uintptr_t raw = Serializer::serialize(&original);

    Data* copy = Serializer::deserialize(raw);

    if (copy == &original) {
        std::cout << "Success: Pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }

    std::cout << "Data content:" << std::endl;
    std::cout << "id: " << copy->id << std::endl;
    std::cout << "name: " << copy->name << std::endl;
    std::cout << "value: " << copy->value << std::endl;

    return 0;
}