#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
// Build the lexicographically largest subsequence of length k while preserving order.
std::string maxSubsequence(const std::string& s, int k) {
    // Keep only digits (defensive; remove if your input is guaranteed numeric).
    std::string line;
    line.reserve(s.size());
    for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) line.push_back(c);

    int n = (int)line.size();
    if (n < k) return ""; // no valid 12-digit subsequence
    int to_remove = n - k;

    std::string res;
    res.reserve(k);
    for (char c : line) {
        while (!res.empty() && to_remove > 0 && res.back() < c) {
            res.pop_back();
            --to_remove;
        }
        res.push_back(c);
    }

    if ((int)res.size() > k) res.resize(k);
    return res;
}

using i128 = __int128;


i128 addToTotal(i128 total, const std::string& num) {

    i128 val = 0;
    for (char c : num) {
        val = val * 10 + (c - '0');
    }
    return total + val;
}


void printI128(i128 x) {
    if (x == 0) { std::cout << 0; return; }
    if (x < 0) { std::cout << '-'; x = -x; }
    std::string s;
    while (x > 0) {
        int digit = (int)(x % 10);
        s.push_back(char('0' + digit));
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

int main() {
    std::ifstream file("day3.txt");
    if (!file) {
        std::cerr << "Failed to open day3.txt\n";
        return 1;
    }

    std::string line;
    i128 total = 0;

    while (std::getline(file, line)) {
        std::string best12 = maxSubsequence(line, 12);
        if (best12.size() == 12) {
            total = addToTotal(total, best12);
        }

    }

    printI128(total);
    std::cout << std::endl;
    return 0;
}
