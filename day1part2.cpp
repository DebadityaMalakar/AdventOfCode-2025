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

        char direction = rotation[0];
        int distance = std::stoi(rotation.substr(1));
        int start = currentPosition;
        int end;

        if (direction == 'L') {
            end = (start - distance) % 100;
        } else { // 'R'
            end = (start + distance) % 100;
        }
        
        if (end < 0) end += 100;

        if (direction == 'R') {

            for (int i = 1; i <= distance; i++) {
                int pos = (start + i) % 100;
                if (pos == 0) {
                    countZero++;
                }
            }
        } else {
            for (int i = 1; i <= distance; i++) {
                int pos = (start - i) % 100;
                if (pos < 0) pos += 100;
                if (pos == 0) {
                    countZero++;
                }
            }
        }

        currentPosition = end;
    }

    inputFile.close();
    
    std::cout << "Password (Part 2): " << countZero << std::endl;
    
    return 0;
}