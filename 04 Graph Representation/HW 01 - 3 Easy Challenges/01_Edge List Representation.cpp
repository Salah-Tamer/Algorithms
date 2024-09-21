#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge{
public:
    int from;
    int to;
    int cost;

    edge(int f, int t, int c) : from(f), to(t), cost(c) {}

    bool operator < (const edge &b){
        return cost < b.cost;
    }
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost){
    graph.push_back({from, to, cost});
}

void print_adj_matrix(GRAPH &graph){
    for(const auto& e : graph){
        cout << "From " << e.from << " to " << e.to << " the cost is " << e.cost << endl;
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph;

    for(int e = 0; e < edges; e++){
        int from, to, cost;
        cin >> from >> to >> cost;
        add_edge(graph, from, to, cost);
    }

    sort(graph.begin(), graph.end());

    print_adj_matrix(graph);
}