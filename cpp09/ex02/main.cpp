#include "PmergeMe.hpp"

int main(int ac, char* av[]) {
    try {
        if (ac < 2) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::vector<std::string> input;
        for (int i = 1; i < ac; ++i) {
            input.push_back(std::string(av[i]));
        }
        PmergeMe sorter;
        sorter.setInput(input);
        sorter.sort();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}