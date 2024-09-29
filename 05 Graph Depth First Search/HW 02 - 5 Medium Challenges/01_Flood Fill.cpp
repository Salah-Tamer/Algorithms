// https://leetcode.com/problems/flood-fill/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isValid(int r, int c, vector<vector<int>> &matrix){
        if(r < 0 || r >= matrix.size()){
            return false;
        }
        if(c < 0 || c >= matrix[0].size()){
            return false;
        }

        return true;
    }
    void dfs(int sr, int sc, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int oldColor, int newColor){
        if(!isValid(sr, sc, matrix) || visited[sr][sc] || matrix[sr][sc] != oldColor){
            return;
        }

        visited[sr][sc] = true, matrix[sr][sc] = newColor;
        
        dfs(sr + 1, sc, matrix, visited, oldColor, newColor);
        dfs(sr, sc - 1, matrix, visited, oldColor, newColor);
        dfs(sr, sc + 1, matrix, visited, oldColor, newColor);
        dfs(sr - 1, sc, matrix, visited, oldColor, newColor); 
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
        dfs(sr, sc, image, visited, image[sr][sc], color);

        return image;
    }
};

int main(){

}