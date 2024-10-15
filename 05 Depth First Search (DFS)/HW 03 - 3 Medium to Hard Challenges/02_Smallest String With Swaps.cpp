#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> GRAPH;

void undirected_edge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(GRAPH &graph, int node, vector<bool> &visited, vector<int> &cc_nodes){
    visited[node] = true;
    cc_nodes.push_back(node);

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(graph, neighbor, visited, cc_nodes);
        }
    }
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int nodes = s.size();
        GRAPH graph(nodes);

        for(int i = 0; i < pairs.size(); i++){
            undirected_edge(graph, pairs[i][0], pairs[i][1]);
        }

        vector<bool> visited(nodes, 0);

        for(int i = 0; i < nodes; i++){
            if(!visited[i]){
                vector<int> cc_nodes;
                dfs(graph, i, visited, cc_nodes);

                string cc_letters;
                for(int node : cc_nodes){
                    cc_letters += s[node];
                }

                sort(cc_letters.begin(), cc_letters.end());
                sort(cc_nodes.begin(), cc_nodes.end());

                for(int i = 0; i < cc_nodes.size(); i++){
                    s[cc_nodes[i]] = cc_letters[i];
                }
            }
        }

        return s;
    }
};

int main(){
    
}