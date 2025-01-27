// https://leetcode.com/problems/water-and-jug-problem/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
bool canMeasureWater(int x, int y, int target) {
    if(x + y < target) return false;
    if(x + y == target || x == target || y == target) return true;

    unordered_map<int, unordered_set<int>> visited;
    visited[0].insert(0);

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();

        if(a + b == target) return true;

        //Generate all possible states
        vector<pair<int, int>> states = {
            {x, b},
            {a, y},
            {0, b},
            {a, 0},
            {a - min(a, y - b), b + min(a, y - b)}, //Pour from x to y
            {a + min(b, x - a), b - min(b, x - a)} // Poure from y to x
        };

        for(auto state : states){
            int newA = state.first, newB = state.second;
            if(visited.find(newA) == visited.end() || visited[newA].find(newB) == visited[newA].end()){
                visited[newA].insert(newB);
                q.push({newA, newB});
            }
        }
    }

    return false;
}
};

int main(){

}