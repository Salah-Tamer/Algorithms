// https://leetcode.com/problems/path-with-minimum-effort/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isValid(vector<vector<int>> &matrix, int r, int c) {
        if (r < 0 || r >= matrix.size()) {
            return false;
        }
        if (c < 0 || c >= matrix[0].size()) {
            return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c, int maxEffort) {
        if (r == heights.size() - 1 && c == heights[0].size() - 1) {
            return true; // Reached destination
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(heights, nr, nc) && !visited[nr][nc]) {
                int diff = abs(heights[nr][nc] - heights[r][c]);
                if (diff <= maxEffort) {
                    if (dfs(heights, visited, nr, nc, maxEffort)) {
                        return true;
                    }
                }
            }
        }

        return false; // No valid path found
    }

    bool possible(vector<vector<int>> &heights, int mid) {
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        return dfs(heights, visited, 0, 0, mid);
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        int maxDiff = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i > 0) {
                    maxDiff = max(maxDiff, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    maxDiff = max(maxDiff, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }

        int start = 0;
        int end = maxDiff;
        int result = end;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (possible(heights, mid)) {
                end = mid - 1;
                result = mid;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};

int mian(){

}