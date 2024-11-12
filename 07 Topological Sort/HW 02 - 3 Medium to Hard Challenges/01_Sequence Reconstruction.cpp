#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> toposort(unordered_map<int, vector<int>> &adjList){
    unordered_map<int, int> indegree;
    for(auto &node : adjList){
        for(int j : node.second){
            indegree[j]++;
        }
    }

    queue<int> ready;
    for(auto &node : adjList){
        if(!indegree.count(node.first)){
            ready.push(node.first);
        }
    }

    vector<int> ordering;
    while(!ready.empty()){
        if(ready.size() > 1) return {};

        int curr = ready.front();
        ordering.push_back(curr);
        ready.pop();

        for(int neighbor : adjList[curr]){
            if(--indegree[neighbor] == 0){
                ready.push(neighbor);
            }
        }
    }

    if(ordering.size() != adjList.size()) return {};

    return ordering;
}

bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs){
    unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < seqs.size(); i++){
        for(int j = 1; j < seqs[i].size(); j++){
            int from = seqs[i][j - 1];
            int to = seqs[i][j];

            adjList[from].push_back(to);
        }
    }

    //handling special case: seqence with single value

    for(auto &seq : seqs){
        if(seq.size() == 1 && adjList.count(seq[0] == 0)){
            adjList[seq[0]] = {};
        }
    }

    vector<int> ordering = toposort(adjList);
    if(ordering != org) return false;

    return true;
}

int main(){
    vector<int> org = {4,1,5,2,6,3};
    vector<vector<int>> seqs = {{5,2,6,3}, {4,1,5,2}};
    cout << sequenceReconstruction(org, seqs); 
}