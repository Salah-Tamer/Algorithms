#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

void addDirectedGraph(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
}

void buildGraph(GRAPH &graph, vector<int> &pid, vector<int> &ppid){
    for(int i = 0; i < pid.size(); i++){
        addDirectedGraph(graph, ppid[i], pid[i]);
    }
}

void dfs(GRAPH &graph, int node, unordered_set<int> &visited){
    visited.insert(node);

    for(int neighbour : graph[node]){
        if(!visited.count(neighbour)){
            dfs(graph, neighbour, visited);
        }
    }
}

vector<int> reachability(GRAPH &graph, int node){
    unordered_set<int> visited;
    dfs(graph, node, visited);
    return vector<int>(visited.begin(), visited.end());
}

vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill){
    GRAPH graph;
    buildGraph(graph, pid, ppid);
    return reachability(graph, kill);
}

int main(){
    vector<int> pid = {5, 0, 1, 2, 6, 3, 4};  // Node IDs
    vector<int> ppid = {0, 5, 5, 5, 2, 2, 1};  // Parent IDs

    int kill = 5;

    vector<int> result = killProcess(pid, ppid, kill);
    for (int id : result) {
        cout << id << " ";
    }
    return 0;
}