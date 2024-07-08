#include <iostream>
#include <fstream>

int main(int ac, char *argv[]) {
    if (ac != 4) {
        std::cout << "You must enter 4 arguments." << std::endl;
        return (1);
    }

    std::ifstream infile(argv[1]);
    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    int    findIn;
    std::string lines;
    std::string line;
    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            findIn = line.find(s1);
            while (findIn != -1) {
                findIn = line.find(s1);
                if (findIn != -1) {
                    line.erase(findIn, s1.length());
                    line.insert(findIn, s2);
                }
            }
            lines += line + '\n';
        }
        infile.close();
        outfile << lines;
    }
}
