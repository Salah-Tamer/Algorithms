#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    bool bfs_cycle(vector<vector<int>> &edges, int start, vector<bool> &visited, vector<int> &parent) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : edges[curr]) {
                if (neighbor == parent[curr]) {
                    continue;
                }
                
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = curr; 
                } else {
                    // If a visited node is found and it's not the parent, a cycle exists
                    return true;
                }
            }
        }
        return false;
    }

    bool has_cycle(vector<vector<int>> &edges, int n) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);  

        if(bfs_cycle(edges, 0, visited, parent)){
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        // Create an adjacency list
        vector<vector<int>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        
        if (has_cycle(adj, n)) {
            return false;  
        }

        return true;
    }
};

int main(){

}