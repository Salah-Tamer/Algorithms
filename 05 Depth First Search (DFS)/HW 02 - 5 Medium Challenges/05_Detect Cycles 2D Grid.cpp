// https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dr[4] = {1, 0, -1, 0}; 
    int dc[4] = {0, 1, 0, -1}; 

    bool isValid(int r, int c, vector<vector<char>> &grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &grid, char oldColor, bool &cycleDetected, int prevR = -1, int prevC = -1) {
        if (!isValid(r, c, grid) || grid[r][c] != oldColor) {
            return; 
        }

        if (visited[r][c]) {
            cycleDetected = true; 
            return; 
        }

        visited[r][c] = true; 

        for (int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if ((newR == prevR && newC == prevC)) {
                continue; // do not visit your parent
            }

            dfs(newR, newC, visited, grid, oldColor, cycleDetected, r, c);
        }

    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!visited[r][c]) { 
                    bool cycleDetected = false; 
                    dfs(r, c, visited, grid, grid[r][c], cycleDetected); 
                    if (cycleDetected) {
                        return true; 
                    }
                }
            }
        }

        return false; 
    }
};

int main(){

}