// https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    bool topsort(vector<vector<int>> &adj){
        int sz = adj.size();
        vector<int> indegree(sz, 0);

        for(int i = 0; i < sz; i++){
            for(int j : adj[i]){
                indegree[j]++;
            }
        }

        queue<int> ready;
        for(int i = 0; i < sz; i++){
            if(!indegree[i]){
                ready.push(i);
            }
        }

        vector<int> ordering;
        while(!ready.empty()){
            int curr = ready.front();
            ready.pop();
            ordering.push_back(curr);

            for(int neighbor : adj[curr]){
                if(--indegree[neighbor] == 0){
                    ready.push(neighbor);
                }
            }
        }

        if(ordering.size() != sz){
            return false;
        }

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < pre.size(); i++){
            int from = pre[i][1];
            int to = pre[i][0];

            adj[from].push_back(to);
        }

        return topsort(adj);
    }
};

int main(){
    
}