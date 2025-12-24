#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int rows, cols;
vector<string> grid;
map<pair<int, int>, long long> memo;

long long countTimelines(int row, int col) {
    if (row >= rows || col < 0 || col >= cols) {
        return 1;
    }
    
    pair<int, int> pos = {row, col};
    
    if (memo.find(pos) != memo.end()) {
        return memo[pos];
    }
    
    char cell = grid[row][col];
    
    if (cell == '^') {
        long long leftCount = countTimelines(row + 1, col - 1);
        long long rightCount = countTimelines(row + 1, col + 1);
        memo[pos] = leftCount + rightCount;
        return memo[pos];
    }
    
    long long result = countTimelines(row + 1, col);
    memo[pos] = result;
    return result;
}

int main() {
    ifstream file("day7.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    
    string line;
    
    while (getline(file, line)) {
        grid.push_back(line);
    }
    file.close();
    
    if (grid.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    rows = grid.size();
    cols = grid[0].length();
    
    int startCol = -1;
    for (int col = 0; col < cols; col++) {
        if (grid[0][col] == 'S') {
            startCol = col;
            break;
        }
    }
    
    if (startCol == -1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long result = countTimelines(1, startCol);
    
    cout << result << endl;
    
    return 0;
}