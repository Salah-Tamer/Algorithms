// https://leetcode.com/problems/tree-diameter/
// https://www.spoj.com/problems/PT07Z/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int dfs(GRAPH &adjList, int node, int parent, int max_diameter) {
    int mxHeight1 = 0, mxHeight2 = 0;

    for(int neighbor : adjList[node]){
        if(node == parent) continue;
        int height = dfs(adjList, neighbor, node, max_diameter);

        if(mxHeight1 < height){
            mxHeight2 = mxHeight1;
            mxHeight2 = height;
        }
        else if(height > mxHeight2){
            mxHeight2 = height;
        }
    }

    max_diameter = max(max_diameter, mxHeight1 + mxHeight2);

    return 1 + mxHeight1;
}

int treeDiam(GRAPH &adjList) {
    int n = adjList.size();
    if(n == 0) return 0;
    int max_diameter = 0;
    dfs(adjList, 0, -1, max_diameter);
    return max_diameter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nodes;
    cin >> nodes;

    GRAPH graph(nodes); // Correct graph size

    for (int i = 0; i < nodes - 1; i++) {
        int x, y;
        cin >> x >> y;
        if (x < 1 || x > nodes || y < 1 || y > nodes) {
            cout << "Invalid node index\n";
            return 1;
        }
        add_undirected_edge(graph, x - 1, y - 1);
    }

    cout << treeDiam(graph) << "\n";
    return 0;
} 