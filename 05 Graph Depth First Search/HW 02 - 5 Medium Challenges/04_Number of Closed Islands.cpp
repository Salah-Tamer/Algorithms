// https://leetcode.com/problems/number-of-closed-islands/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};

    bool isValid(int r, int c, vector<vector<int>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
    }

    bool isGridBoundry(int r, int c, vector<vector<int>> &grid){
        if(r == 0 || r == grid.size() - 1){
            return true;
        }
        if(c == 0 || c == grid[0].size() - 1){
            return true;
        }

        return false;
    }

    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& grid, bool &is_touched_boundry) {
        if(!isValid(r, c, grid) || visited[r][c] || grid[r][c] == 1){
            return;
        }

        visited[r][c] = true;
        if(isGridBoundry(r, c, grid)){
            is_touched_boundry = true;
        }

        for(int i = 0; i < 4; i++){
            dfs(r + dr[i], c + dc[i], visited, grid, is_touched_boundry);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));

        int count = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                bool is_touched_boundry = false;
                if(grid[r][c] == 0 && !visited[r][c]){
                    dfs(r, c, visited, grid, is_touched_boundry);
                    count += !is_touched_boundry;
                }
            }
        }

        return count;
    }
};


int main(){

}