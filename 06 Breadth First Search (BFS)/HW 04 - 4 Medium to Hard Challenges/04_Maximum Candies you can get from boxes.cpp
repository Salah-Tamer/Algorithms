// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> visited(n, 0); 
        queue<int> q;
        unordered_set<int> lockedBoxes; 
        unordered_set<int> availableKeys;
        
        for (int box : initialBoxes) {
            if (status[box] == 1) {
                q.push(box); 
            } else {
                lockedBoxes.insert(box); 
            }
        }

        int countCandies = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if(visited[curr]) continue;
            visited[curr] = 1;

            countCandies += candies[curr];

            for(int box : containedBoxes[curr]){
                if(status[box] == 1 || availableKeys.count(box)){
                    q.push(box);
                }
                else{
                    lockedBoxes.insert(box);
                }
            }

            for(int key : keys[curr]){
                availableKeys.insert(key);
                if(lockedBoxes.count(key)){
                    q.push(key);
                    availableKeys.erase(key);
                }
            }
        }

        return countCandies;
    }
};

int main(){

}