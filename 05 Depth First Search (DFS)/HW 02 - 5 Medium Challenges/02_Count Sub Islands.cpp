// https://leetcode.com/problems/count-sub-islands/description/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, vector<vector<int>> &matrix){
        if(r < 0 || r >= matrix.size()){
            return false;
        }
        if(c < 0 || c >= matrix[0].size()){
            return false;
        }
        return true;
    }

    void dfs(int r, int c, bool &isSubIsland, vector<vector<int>> &grid1, vector<vector<int>> &grid2){
        if(!isValid(r, c, grid2) || grid2[r][c] == 0){
            return;
        }

        if(!grid1[r][c] && grid2[r][c]){
            isSubIsland = false;
            return;
        }

        grid2[r][c] = 0;

        for(int i = 0; i < 4; i++){
            dfs(r + dr[i], c + dc[i], isSubIsland, grid1, grid2);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int r = 0; r < grid1.size(); r++){
            for(int c = 0; c < grid1[0].size(); c++){
                if(grid2[r][c]){
                    bool isSubIsland = true;
                    dfs(r, c, isSubIsland, grid1, grid2);
                    count += isSubIsland;
                }
            }
        }

        return count;
    }
};


int main(){

}