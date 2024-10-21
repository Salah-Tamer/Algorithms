// https://leetcode.com/problems/jump-game-iii/description/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    bool isValid(int length, int to) {
        return to >= 0 && to < length; 
    }

    void directed_edge(vector<vector<int>> &graph, int from, int to) {
        if (isValid(graph.size(), to)) { 
            graph[from].push_back(to);
        }
    }

    bool bfs(vector<vector<int>> &graph, int idx, vector<int> &arr, vector<bool> &visited) {
        queue<int> q;
        q.push(idx);
        visited[idx] = true; 

        while (!q.empty()) {
            int currIdx = q.front();
            q.pop();

            if (arr[currIdx] == 0) {
                return true; // Reachable index with value 0
            }

            for(int neighbor : graph[currIdx]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[currIdx] = true;
                }
            }
        }

        return false; // No reachable index with value 0
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int length = arr.size();
        vector<vector<int>> graph(length); 
        vector<bool> visited(length, false); 

        
        for (int i = 0; i < length; i++) {
            int from = i;

            if (isValid(length, from + arr[i])) {
                directed_edge(graph, from, from + arr[i]);
            }

            if (isValid(length, from - arr[i])) {
                directed_edge(graph, from, from - arr[i]);
            }
        }

        return bfs(graph, start, arr, visited); 
    }
};

int main(){

}