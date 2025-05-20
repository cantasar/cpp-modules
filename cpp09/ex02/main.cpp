#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac <= 2) {
        std::cout << "Error\n";
        return 1;
    }

    PmergeMe sort;
    sort.execute(ac, av);
}
