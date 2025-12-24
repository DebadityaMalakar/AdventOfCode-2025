#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("day5.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    
    string line;
    vector<pair<long long, long long>> ranges;
    
    while (getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        
        if (line.empty()) {
            break;
        }
        
        size_t dashPos = line.find('-');
        if (dashPos != string::npos && dashPos > 0 && dashPos < line.length() - 1) {
            string startStr = line.substr(0, dashPos);
            string endStr = line.substr(dashPos + 1);
            long long start = stoll(startStr);
            long long end = stoll(endStr);
            ranges.push_back({start, end});
        }
    }
    file.close();
    
    sort(ranges.begin(), ranges.end());
    
    vector<pair<long long, long long>> merged;
    for (const auto& range : ranges) {
        if (merged.empty() || merged.back().second < range.first - 1) {
            merged.push_back(range);
        } else {
            merged.back().second = max(merged.back().second, range.second);
        }
    }
    
    long long totalFresh = 0;
    for (const auto& range : merged) {
        totalFresh += range.second - range.first + 1;
    }
    
    cout << totalFresh << endl;
    
    return 0;
}