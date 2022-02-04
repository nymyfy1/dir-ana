#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void dir_iterator(std::string fpath) {
    if (!fs::exists(fpath)) {
        std::cout << "Directory not found.\n";
        return;
    }

    std::string st;

    int nb = std::count_if(fs::directory_iterator(fpath), fs::directory_iterator(), static_cast<bool(*)(const fs::path&)>(fs::is_regular_file));
    std::cout << fpath << " edirectory" << " has " << nb << " file/s\n";

    for (auto entry : fs::recursive_directory_iterator(fpath)) {
        std::ifstream inf;
        if (entry.is_regular_file()) {
            inf.open(entry);
            nb = 0;
            while (!inf.eof()) {
                getline(inf, st);
                nb++;

            }
            inf.close();
            std::cout << entry << " file" <<" has " << nb << " line/s\n";
        } else if (entry.is_directory()) {
            nb = std::count_if(fs::directory_iterator(entry), fs::directory_iterator(), static_cast<bool(*)(const fs::path&)>(fs::is_regular_file));
            std::cout << entry << " directory" << " has " << nb << " file/s\n";
        }
    }
}

int main() {
    int threads = std::thread::hardware_concurrency(); 
    std::string fpath;
    std::cout << "Enter directory:" << "\n";
    getline(std::cin, fpath);
    dir_iterator(fpath);

    //std::cout << "available threads: " << threads << std::endl;

    system("pause");

    return 0;
}