#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return {0};

        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int from = edges[i][0];
            int to = edges[i][1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        for(int i = 0; i < adj.size(); i++){
            for(int j : adj[i]){
                indegree[j]++;
            }
        }
        queue<int> leaves;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                leaves.push(i);
            }
        }

        int remainingNodes = n;
        while(remainingNodes > 2){
            int levelSize = leaves.size();
            remainingNodes -= levelSize;

            while(levelSize--){
                int curr = leaves.front();
                leaves.pop();

                for(int neighbor : adj[curr]){
                    if(--indegree[neighbor] == 1){
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> res;
        while(!leaves.empty()){
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};

int main(){

}