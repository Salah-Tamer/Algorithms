#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;

        for (const auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int startNode = 0;
        for (const auto& node : graph) {
            if (node.second.size() == 1) {
                startNode = node.first;
                break;
            }
        }

        unordered_set<int> visited;
        dfs(startNode, res, visited);

        return res;
    }

    void dfs(int node, vector<int>& res, unordered_set<int> &visited) {
        visited.insert(node);
        res.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor,  res, visited);
            }
        }
    }
};

int main(){

}