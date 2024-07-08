#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl harl;
	if (argc == 2)
	{
        int i = 0;

        std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

        while (i < 4 && argv[1] != levels[i])
            i++;

        switch (i)
        {
			case 0:
				std::cout << "[" << levels[0] << "]" << std::endl;
				harl.complain(levels[0]);
				std::cout << std::endl;
				break;
			case 1:
				std::cout << "[" << levels[1] << "]" << std::endl;
				harl.complain(levels[1]);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "[" << levels[2] << "]" << std::endl;
				harl.complain(levels[2]);
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "[" << levels[3] << "]" << std::endl;
				harl.complain(levels[3]);
				std::cout << std::endl;
				break;
			default:
            	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
        }
	}
	
	return 0;
}

