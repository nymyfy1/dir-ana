#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

void dir_iterator(std::string path) {
    for (const auto entry : fs::recursive_directory_iterator(path)){
        std::cout << entry << "\n";
    }
}

int main() {
    int threads = std::thread::hardware_concurrency(); 
    std::string path;
    std::cout << "Enter directory:" << "\n";
    getline(std::cin, path);
    dir_iterator(path);

    //std::cout << threads << std::endl;
    return 0;
}