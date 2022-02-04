#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void iterate(auto entry) {
    if (entry.is_regular_file()) {
        std::ifstream inf;
        std::string st;
        inf.open(entry);
        int nb = 0;
        while (!inf.eof()) {
            getline(inf, st);
            nb++;

        }
        inf.close();
        std::cout << entry << " file" << " has " << nb << " line/s\n";
    }
    else if (entry.is_directory()) {
        int nb = std::count_if(fs::directory_iterator(entry), fs::directory_iterator(), static_cast<bool(*)(const fs::path&)>(fs::is_regular_file));
        std::cout << entry << " directory" << " has " << nb << " file/s\n";
    }
}

void dir_iterator(std::string fpath) {
    if (!fs::exists(fpath)) {
        std::cout << "Directory not found.\n";
        return;
    }

    int threadnb = std::thread::hardware_concurrency();

    int nb = std::count_if(fs::directory_iterator(fpath), fs::directory_iterator(), static_cast<bool(*)(const fs::path&)>(fs::is_regular_file));
    std::cout << fpath << " directory" << " has " << nb << " file/s\n";
    for (auto entry : fs::recursive_directory_iterator(fpath)) {
        iterate(entry);
    }
}

int main() {
    std::string fpath;
    std::cout << "Enter directory:" << "\n";
    getline(std::cin, fpath);
    dir_iterator(fpath);

    system("pause");

    return 0;
}