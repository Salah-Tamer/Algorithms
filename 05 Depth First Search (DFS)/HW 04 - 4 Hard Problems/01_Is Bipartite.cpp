// https://leetcode.com/problems/is-graph-bipartite/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool is_color_conflict = 0;
    void dfs(vector<vector<int>> &graph, int node, vector<int> &colors, int assigned_color = 1){
        if(colors[node] == 0){
            colors[node] = assigned_color;
        }
        else{
            if(colors[node] != assigned_color){
                is_color_conflict = 1;
            }

            return;
        }


        for(int neighbour : graph[node]){
            dfs(graph, neighbour, colors, 3 - assigned_color);
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> colors(nodes, 0);


        for(int i = 0; i < graph.size(); i++){
            if(colors[i] == 0){
                dfs(graph, i, colors);
                if(is_color_conflict){
                    return false;
                }
            }
        }


        return true;
    }
};

int main(){

}