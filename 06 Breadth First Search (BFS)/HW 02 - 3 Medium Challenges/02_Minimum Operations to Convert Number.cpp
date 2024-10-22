// https://leetcode.com/problems/minimum-operations-to-convert-number/description/

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    bool check(queue<int> &q, unordered_set<int> &visited, int num, int goal){
        if(num == goal) return true;

        if(num >= 0 && num <= 1000 && visited.find(num) == visited.end()){
            visited.insert(num);
            q.push(num);
        }

        return false;
    }
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);

        int count = 0;
        int numsSize = nums.size();

        while(!q.empty()){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                int currIdx = q.front();
                q.pop();

                for(int num : nums){
                    if(check(q, visited, currIdx + num, goal) || 
                        check(q, visited, currIdx - num, goal) ||
                        check(q, visited, currIdx ^ num, goal))
                    {
                        return count + 1;
                    }
                }
            }

            count++;
        }

        return -1;

    }
};

int main(){

}