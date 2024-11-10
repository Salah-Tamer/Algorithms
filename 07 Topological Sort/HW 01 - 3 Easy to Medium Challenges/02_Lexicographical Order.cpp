#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Complexity: O((V + E) log V)
vector<int> toposort(vector<vector<int>> &adj){
    vector<vector<int>> res;
    int size = adj.size();
    vector<int> indegree(size, 0);

    for(int i = 0; i < size; i++){
        for(int j : adj[i]){
            indegree[j]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> ready;
    for(int i = 0; i < size; i++){
        if(!indegree[i]){
            ready.push(i);
        }
    }

    vector<int> ordering;
    while(!ready.empty()){
        int curr = ready.top();
        ordering.push_back(curr);
        ready.pop();

        for(int neighbor : adj[curr]){
            if(--indegree[neighbor] == 0){
                ready.push(neighbor);
            }
        }
    }

    if(ordering.size() != size){
        return {};
    }

    return ordering;
}

int main(){


    int nodes = 9;
    vector<vector<int>> adjList(nodes);

    adjList[4].push_back(7);
    adjList[7].push_back(1);
    adjList[2].push_back(5);
    adjList[5].push_back(6);
    adjList[5].push_back(3);

    vector<int> res = toposort(adjList);

    for(int i : res){
        cout << i << " ";
    }
}