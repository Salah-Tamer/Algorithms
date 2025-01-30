// https://leetcode.com/problems/shortest-bridge/description/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};

    bool isValid(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[0].size()) return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>> &q, int r, int c){
        if(!isValid(grid, r, c) || visited[r][c] || grid[r][c] == 0) return;

        visited[r][c] = 1;
        q.push({r, c});

        for(int i = 0; i < 4; i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            dfs(grid, visited, q, nr, nc);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;

        bool found = false;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    dfs(grid, visited, q, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }


        int count = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int r = q.front().first, c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = dr[i] + r;
                    int nc = dc[i] + c;

                    if(isValid(grid, nr, nc) && !visited[nr][nc]){
                        if(grid[nr][nc] == 1){
                            return count;
                        }
                        q.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }

            count++;
        }

        return -1;
    }
};

int main(){

}