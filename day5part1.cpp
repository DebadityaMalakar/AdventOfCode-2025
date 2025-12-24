#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("day5.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    
    string line;
    vector<pair<long long, long long>> ranges;
    vector<long long> ingredients;
    bool readingRanges = true;
    
    while (getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        
        if (line.empty()) {
            readingRanges = false;
            continue;
        }
        
        try {
            if (readingRanges) {
                size_t dashPos = line.find('-');
                if (dashPos != string::npos && dashPos > 0 && dashPos < line.length() - 1) {
                    string startStr = line.substr(0, dashPos);
                    string endStr = line.substr(dashPos + 1);
                    long long start = stoll(startStr);
                    long long end = stoll(endStr);
                    ranges.push_back({start, end});
                }
            } else {
                if (!line.empty()) {
                    long long ingredient = stoll(line);
                    ingredients.push_back(ingredient);
                }
            }
        } catch (const exception& e) {
            cerr << "Error parsing line: " << line << " - " << e.what() << endl;
        }
    }
    file.close();
    
    int freshCount = 0;
    for (long long ingredient : ingredients) {
        bool isFresh = false;
        for (const auto& range : ranges) {
            if (ingredient >= range.first && ingredient <= range.second) {
                isFresh = true;
                break;
            }
        }
        if (isFresh) {
            freshCount++;
        }
    }
    
    cout << freshCount << endl;
    
    return 0;
}