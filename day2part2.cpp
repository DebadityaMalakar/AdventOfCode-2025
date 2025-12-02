#include <iostream>
#include <string>
#include <sstream>

bool isInvalid(long long num) {
    std::string s = std::to_string(num);
    int len = s.length();
    
    for (int repeat = 2; repeat <= len; repeat++) {
        if (len % repeat != 0) continue;
        
        int partLen = len / repeat;
        bool valid = true;
        std::string part = s.substr(0, partLen);
        
        for (int i = 1; i < repeat; i++) {
            if (s.substr(i * partLen, partLen) != part) {
                valid = false;
                break;
            }
        }
        
        if (valid) return true;
    }
    
    return false;
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