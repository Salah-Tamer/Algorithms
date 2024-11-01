// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool isValid(vector<vector<int>> &matrix, int r, int c){
        if(r < 0 || r >= matrix.size()){
            return false;
        }

        if(c < 0 || c >= matrix[0].size()){
            return false;
        }

        return true;
    }

    void bfs(vector<vector<int>>& matrix, vector<vector<bool>> &visited, vector<pair<int, int>> &startings){
        queue<pair<int, int>> q;
        for(auto pair : startings){
            q.push(pair);
            visited[pair.first][pair.second] = true;
        }

        while(!q.empty()){
            int levelSize = q.size();

            while(levelSize--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(!isValid(matrix, nr, nc) || visited[nr][nc] || matrix[r][c] > matrix[nr][nc]){
                        continue;
                    }

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<pair<int, int>> pacificStartings, atlanticStartings;

        for(int r = 0; r < rows; r++){
            pacificStartings.push_back({r, 0});
            atlanticStartings.push_back({r, cols - 1});
        }

        for(int c = 0; c < cols; c++){
            pacificStartings.push_back({0, c});
            atlanticStartings.push_back({rows - 1, c});
        }

        vector<vector<bool>> pacificReachable(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticReachable(rows, vector<bool>(cols, false));

        bfs(heights, pacificReachable, pacificStartings);
        bfs(heights, atlanticReachable, atlanticStartings);

        vector<vector<int>> result;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacificReachable[i][j] && atlanticReachable[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main(){


}