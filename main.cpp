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

    inFile >> tmp;
    while (!inFile.eof()) {
        data.push_back(tmp);
        inFile >> tmp;
    }
    inFile.close();
    return data;
}

int main(int argc, char* argv[]) {
    if (argc > 0) {
        std::vector<unsigned char> data = readFile(argv[1]);
        dbg::DEBUG_BUFFER(data);
        parser p;
        p.parse(data);
    } else {
        std::cout << "USAGE: ./jolt <path_to_classfile>" << "\n";
    }
    return 0;
}
