#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void AddUnDirectedEdge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void BuildGraphFromEdgeList(GRAPH &graph, vector<vector<int>> &edges){
    for(int i = 0; i < edges.size(); i++){
        int from = edges[i][0];
        int to = edges[i][1];
        AddUnDirectedEdge(graph, from, to);
    }
}

void dfs(vector<vector<int>> &edges, int node, vector<bool> &visited){
    visited[node] = 1;

    for(int neighbour : edges[node]){
        if(!visited[neighbour]){
            dfs(edges, neighbour, visited);
        }
    }
}

int CountComponents(int n, vector<vector<int>> &edges){
    GRAPH graph(n);
    BuildGraphFromEdgeList(graph, edges);

    vector<bool> visited(n, 0);
    int count = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(graph, i, visited);
        }
    }

    return count;
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int n = 5;
    cout << CountComponents(n, edges);
}