#include <iostream>
#include <string>
#include <sstream>

bool isInvalid(long long num) {
    std::string s = std::to_string(num);
    if (s.length() % 2 != 0) return false;
    return s.substr(0, s.length() / 2) == s.substr(s.length() / 2);
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    
    std::stringstream ss(line);
    std::string part;
    long long total = 0;
    
    while (std::getline(ss, part, ',')) {
        size_t dash = part.find('-');
        long long start = std::stoll(part.substr(0, dash));
        long long end = std::stoll(part.substr(dash + 1));
        
        for (long long i = start; i <= end; i++) {
            if (isInvalid(i)) {
                total += i;
            }
        }
    }
    
    std::cout << total << std::endl;
    
    return 0;
}