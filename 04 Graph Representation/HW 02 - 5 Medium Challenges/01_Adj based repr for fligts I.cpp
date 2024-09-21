#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Edge{
    string to;
    int weight;

    bool operator < (const Edge &e) const{
        if(to != e.to){
            return to < e.to;
        }
        return weight < e.weight;
    }
};

typedef map<string, multiset<Edge>> GRAPH;

void add_directed_edge(GRAPH &graph, string from, string to, int cost){
    graph[from].insert({to, cost});
}

void print_adj_matrix(GRAPH &graph){
    for(auto node: graph){
        cout << "Flights From " << node.first << endl;
        for(const Edge &edge : node.second){
            cout << "\tTo " << edge.to << " with cost "<< edge.weight << endl;
        }
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph;

    for(int e = 0; e < edges; e++){
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }

    print_adj_matrix(graph);
}