#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("day3.txt");
    std::string line;
    long long total = 0;
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        int max_joltage = 0;
        
        for (size_t i = 0; i < line.length(); i++) {
            for (size_t j = i + 1; j < line.length(); j++) {
                std::string combo;
                combo += line[i];
                combo += line[j];
                
                int value = std::stoi(combo);
                if (value > max_joltage) max_joltage = value;
            }
        }
        
        total += max_joltage;
    }
    
    std::cout << total << std::endl;
    
    return 0;
}