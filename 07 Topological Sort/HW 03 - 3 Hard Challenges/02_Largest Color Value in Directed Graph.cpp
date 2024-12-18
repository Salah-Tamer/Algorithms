// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> colorCount(n, vector<int>(26, 0));

        queue<int> ready;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ready.push(i);
            }
        }

        int visitedNodes = 0;
        int maxColorValue = 0;

        while (!ready.empty()) {
            int curr = ready.front();
            int color = colors[curr] - 'a';
            ready.pop();

            visitedNodes++;
            colorCount[curr][color]++;

            // Propagate to neighbors
            for (int neighbor : graph[curr]) {
                for (int c = 0; c < 26; c++) {
                    colorCount[neighbor][c] = max(colorCount[neighbor][c], colorCount[curr][c]);
                }

                if (--indegree[neighbor] == 0) {
                    ready.push(neighbor);
                }
            }

            maxColorValue = max(maxColorValue, *max_element(colorCount[curr].begin(), colorCount[curr].end()));
        }

        return (visitedNodes == n) ? maxColorValue : -1;
    }
};

int main(){

}