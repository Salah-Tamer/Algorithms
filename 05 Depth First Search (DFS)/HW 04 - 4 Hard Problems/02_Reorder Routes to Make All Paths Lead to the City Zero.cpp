// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<pair<int, int>>> GRAPH;  

void add_undirected_edge(GRAPH &graph, int from, int to){
    graph[from].push_back({to, 1});   // Original direction
    graph[to].push_back({from, 0});   // Reverse direction
}

int dfs(GRAPH &graph, vector<bool> &visited, int node){
    visited[node] = true;
    int reorders = 0;

    for(auto [neighbor, direction] : graph[node]){
        if(!visited[neighbor]){
            // If the direction is '1', it's moving away, so we count it
            reorders += direction;
            reorders += dfs(graph, visited, neighbor);
        }
    }

    return reorders;
}

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        GRAPH graph(n);
        for(vector<int> &edge : connections){
            add_undirected_edge(graph, edge[0], edge[1]);
        }

        vector<bool> visited(n, false);
        return dfs(graph, visited, 0);
    }
};

int main(){

}