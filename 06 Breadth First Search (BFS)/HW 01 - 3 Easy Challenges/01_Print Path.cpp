#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> GRAPH;

vector<int> bfs(GRAPH &graph, int start) {
    vector<int> parent(graph.size(), -1); 
    queue<int> q;
    q.push(start);

    for (int level = 0, size = 1; !q.empty(); level++, size = q.size()) {
        while (size--) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr]) {
                if (parent[neighbor] == -1) { 
                    q.push(neighbor);
                    parent[neighbor] = curr;
                }
            }
        }
    }

    return parent;
}

void print(vector<int> &parent, int start, int node) {
    if(parent[node] == start){
        return;
    }
    print(parent, start, parent[node]);
    cout << node << " ";
}

int main() {
    GRAPH graph = {
        {1, 2},  
        {0, 3, 4}, 
        {0, 5},    
        {1},       
        {1, 5},    
        {2, 4}     
    };

    int start = 0; 
    vector<int> parent = bfs(graph, start);


    for (int node = 1; node < graph.size(); ++node) {
        cout << "Path from " << start << " to " << node << ": ";
        if (parent[node] != -1) { 
            print(parent, start, node);
            cout << endl;
        } else {
            cout << "No path from " << start << " to " << node << endl;
        }
    }

    return 0;
}
