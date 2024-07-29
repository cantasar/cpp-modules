#include <iostream>
#include <fstream>

int main(int ac, char *argv[]) {
    if (ac != 4) {
        std::cout << "You must enter 4 arguments." << std::endl;
        return (1);
    }

    std::ifstream infile;
    infile.open(argv[1]);
    std::ofstream outfile;
    outfile.open((std::string(argv[1]) + ".replace").c_str());

    std::string s_cur = argv[2];
    std::string s_new = argv[3];

    int    find_index;
    std::string lines;
    std::string line;
    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            find_index = line.find(s_cur);
            while (find_index != -1) {
                find_index = line.find(s_cur);
                if (find_index != -1) {
                    line.erase(find_index, s_cur.length());
                    line.insert(find_index, s_new);
                }
            }
            lines += line + '\n';
        }
        infile.close();
        outfile << lines;
    }
    outfile.close();
    return 0;
}
