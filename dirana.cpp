#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void dir_iterator(std::string path) {
    int nb;
    std::string st;
    for (auto entry : fs::recursive_directory_iterator(path)) {
        std::ifstream inf;
        std::cout << path;
        system("pause");
        /*inf.open(path);
        nb = 0;
        while (!inf.eof()) {
            getline(inf, st);
            std::cout << nb++;

        }
        inf.close();*/
        std::cout << entry /*<< " : " << nb*/ << " lines\n";
    }
}

int main() {
    int threads = std::thread::hardware_concurrency(); 
    std::string path;
    std::cout << "Enter directory:" << "\n";
    getline(std::cin, path);
    dir_iterator(path);

    //std::cout << "available threads: " << threads << std::endl;

    system("pause");

    return 0;
}