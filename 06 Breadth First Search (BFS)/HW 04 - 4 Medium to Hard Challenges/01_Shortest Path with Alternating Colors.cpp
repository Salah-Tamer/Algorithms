// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int OO = 10000000;
    int RED = 0;
    int BLUE = 1;

    struct edge{
        int to;
        int color;
    };

    typedef vector<vector<edge>> GRAPH;
    void add_directed_edge(GRAPH &graph, int from, int to, int color){
        graph[from].push_back({to, color});
    }

    vector<int> bfs(GRAPH adjList, int start){
        int nodes = adjList.size();
        vector<int> answer(nodes, -1);
        vector<vector<int>> len(nodes, vector<int>(2, OO));
        queue<edge> q;

        q.push({start, RED});
        q.push({start, BLUE});
        len[start][RED] = len[start][BLUE] = 0;
        answer[start] = 0;

        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int curr = q.front().to, color = q.front().color;
                q.pop();

                for(edge e : adjList[curr]){
                    if(color != e.color && len[e.to][e.color] == OO){
                        q.push(e);
                        len[e.to][e.color] = level + 1;
                        if(answer[e.to] == - 1){
                            answer[e.to] = level + 1;
                        }
                    }
                }
            }

        }

        return answer;

    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        GRAPH adjList(n);
        for(auto &e : redEdges){
            add_directed_edge(adjList, e[0], e[1], RED);
        }

        for(auto &e : blueEdges){
            add_directed_edge(adjList, e[0], e[1], BLUE);
        }

        return bfs(adjList, 0);

    }
};

int main(){

}