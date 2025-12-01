#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream inputFile("day1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file!" << std::endl;
        return 1;
    }

    int currentPosition = 50;
    int countZero = 0;
    std::string rotation;

    while (std::getline(inputFile, rotation)) {
        if (rotation.empty()) continue;

        // Extract direction and distance
        char direction = rotation[0];
        int distance = std::stoi(rotation.substr(1));

        if (direction == 'L') {

            currentPosition = (currentPosition - distance) % 100;
        } else if (direction == 'R') {
            currentPosition = (currentPosition + distance) % 100;
        }

        if (currentPosition < 0) {
            currentPosition += 100;
        }

        if (currentPosition == 0) {
            countZero++;
        }
    }

    inputFile.close();
    
    std::cout << "Password: " << countZero << std::endl;
    
    return 0;
}