#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

int main() {
    ifstream file("day7.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    
    vector<string> grid;
    string line;
    
    while (getline(file, line)) {
        grid.push_back(line);
    }
    file.close();
    
    if (grid.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    int startCol = -1;
    for (int col = 0; col < grid[0].length(); col++) {
        if (grid[0][col] == 'S') {
            startCol = col;
            break;
        }
    }
    
    if (startCol == -1) {
        cout << 0 << endl;
        return 0;
    }
    
    queue<pair<int, int>> beams;
    beams.push({1, startCol});
    
    set<pair<int, int>> seenBeams;
    seenBeams.insert({1, startCol});
    
    int splitCount = 0;
    
    while (!beams.empty()) {
        auto [row, col] = beams.front();
        beams.pop();
        
        while (row < grid.size()) {
            if (col < 0 || col >= grid[row].length()) {
                break;
            }
            
            char cell = grid[row][col];
            
            if (cell == '^') {
                splitCount++;
                
                int leftCol = col - 1;
                int rightCol = col + 1;
                int nextRow = row + 1;
                
                if (nextRow < grid.size()) {
                    if (leftCol >= 0 && seenBeams.find({nextRow, leftCol}) == seenBeams.end()) {
                        beams.push({nextRow, leftCol});
                        seenBeams.insert({nextRow, leftCol});
                    }
                    
                    if (rightCol < grid[nextRow].length() && seenBeams.find({nextRow, rightCol}) == seenBeams.end()) {
                        beams.push({nextRow, rightCol});
                        seenBeams.insert({nextRow, rightCol});
                    }
                }
                
                break;
            }
            
            row++;
            
            if (row < grid.size() && seenBeams.find({row, col}) != seenBeams.end()) {
                break;
            }
            
            if (row < grid.size()) {
                seenBeams.insert({row, col});
            }
        }
    }
    
    cout << splitCount << endl;
    
    return 0;
}