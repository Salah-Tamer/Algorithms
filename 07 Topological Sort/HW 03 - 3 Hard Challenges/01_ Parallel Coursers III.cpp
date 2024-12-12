// https://leetcode.com/problems/parallel-courses-iii/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        GRAPH graph(n + 1);
        vector<int> indegrees(n + 1, 0);
        vector<int> completionTime(n + 1, 0); 

        for (auto& relation : relations) {
            int from = relation[0];
            int to = relation[1];
            graph[from].push_back(to);
            indegrees[to]++;
        }

        queue<int> ready;
        for (int i = 1; i <= n; i++) {
            if (indegrees[i] == 0) {
                ready.push(i);
                completionTime[i] = time[i - 1]; 
            }
        }

        while (!ready.empty()) {
            int curr = ready.front();
            ready.pop();

            for (int neighbor : graph[curr]) {
                // Update the completion time for the dependent course
                completionTime[neighbor] = max(completionTime[neighbor], completionTime[curr] + time[neighbor - 1]);

                if (--indegrees[neighbor] == 0) {
                    ready.push(neighbor);
                }
            }
        }

        return *max_element(completionTime.begin(), completionTime.end());
    }
};

int main(){

}