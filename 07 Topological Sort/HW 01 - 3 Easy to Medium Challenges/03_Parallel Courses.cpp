#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumSemster(vector<vector<int>> &relations){
    int size = relations.size();
    vector<int> indegree(size, 0);

    for(int i = 0; i < size; i++){
        for(int j : relations[i]){
            indegree[j]++;
        }
    }

    queue<int> ready;
    for(int i = 0; i < size; i++){
        if(!indegree[i]){
            ready.push(i);
        }
    }

    int found_nodes = 0;
    int count = 0;
    while(!ready.empty()){
        int levelSize = ready.size();

        while(levelSize--){
            int curr = ready.front();
            found_nodes++;
            ready.pop();

            for(int neighbor : relations[curr]){
                if(--indegree[neighbor] == 0){
                    ready.push(neighbor);
                }
            }
        }

        count++;
    }

    if(found_nodes != size){
        return -1;
    }

    return count;
}

int main(){

   const int vertices = 3;
    
    vector<vector<int>> adjList(vertices + 1);

    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    cout << minimumSemster(adjList);
}