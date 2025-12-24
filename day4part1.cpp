#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("day4.txt");
    std::vector<std::string> grid;
    std::string line;
    
    while (std::getline(file, line)) {
        grid.push_back(line);
    }
    
    int accessible = 0;
    int rows = grid.size();
    
    if (rows == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    int cols = grid[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '@') {
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            if (grid[ni][nj] == '@') count++;
                        }
                    }
                }
                if (count < 4) accessible++;
            }
        }
    }
    
    std::cout << accessible << std::endl;
    
    return 0;
}