#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

void undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int dfs(GRAPH &graph, int node, unordered_set<int> &visited) {
    visited.insert(node);

    int count = 1; // Start counting this node
    for (int neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            count += dfs(graph, neighbor, visited);
        }
    }

    return count; // Return total count of connected nodes
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        if (nums_set.size() == 0) return 0;

        GRAPH graph;
        // Create the graph based on consecutive integers
        for (int num : nums_set) {
            if (nums_set.count(num + 1)) {
                undirected_edge(graph, num, num + 1);
            }
            if (nums_set.count(num - 1)) {
                undirected_edge(graph, num, num - 1);
            }
        }

        unordered_set<int> visited;
        int max_cc_size = 0; // Set to 0 to handle the case of only one node

        // Traverse all nodes in the graph
        for (auto &node_adj : graph) {
            if (!visited.count(node_adj.first)) {
                cout << "Starting DFS from node: " << node_adj.first << endl;
                int cc_size = dfs(graph, node_adj.first, visited);
                cout << "Connected component size: " << cc_size << endl;
                max_cc_size = max(max_cc_size, cc_size);
            }
        }

        return max_cc_size; // Return the maximum size of connected components
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 2, 2, -4, 0, -2, 4, -3, -4, -4, -5, 1, 4, -9, 5, 0, 6, -8, -1, -3, 6, 5, -8, -1, -5, -1, 2, -9, 1};
    int result = solution.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}