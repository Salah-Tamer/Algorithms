#include <iostream>
#include <vector>
using namespace std;

void add_undirected_edge(vector<vector<int>> &adj, int from, int to){
    adj[from].push_back(to);
    adj[to].push_back(from);
}

bool dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, int parent){
    visited[node] = true;

    for(int neighbor : adj[node]){
        if(neighbor == parent) continue;

        if(visited[neighbor]){
            return true; //cycle
        }

        if(!visited[neighbor]){
            if(dfs(adj, neighbor, visited, node)){
                return true;
            }
        }
    }

    return false;
}

bool isCyclic(vector<vector<int>> &adj, int V){
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(dfs(adj, i, visited, -1)){
                return true;
            }
        }
    }

    return false;
}

int main(){

}