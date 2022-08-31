#include <iostream>
#include <fstream>
#include <vector>

#include "debug.h"
#include "parser.h"

std::vector<unsigned char> readFile(std::string const& filename) {
    std::ifstream inFile;
    unsigned char tmp;
    std::vector<unsigned char> data;
    inFile.open(filename);
    if (!inFile) {
        std::cerr << "File Could Not Be Opened!" << std::endl;
        exit(1);
    }

    inFile >> std::noskipws >> tmp;
    while (!inFile.eof()) {
        data.push_back(tmp);
        inFile >> std::noskipws >> tmp;
    }
    inFile.close();
    return data;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "USAGE: ./jolt <path_to_classfile>" << "\n";
        exit(1);
    }

    std::vector<unsigned char> data = readFile(argv[1]);
//    dbg::DEBUG_BUFFER(data);
    Parser parser{data};
    parser.parse();
    return 0;
}
