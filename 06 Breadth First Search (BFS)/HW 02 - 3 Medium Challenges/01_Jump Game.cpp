// https://leetcode.com/problems/jump-game-iii/description/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    bool isValid(int length, int to) {
        return to >= 0 && to < length; 
    }

public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0){
            return true;
        }

        int length = arr.size();
        vector<bool> visited(length, false); 

        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()){
            int currIdx = q.front();
            q.pop();

            int forward = currIdx + arr[currIdx];
            int backward = currIdx - arr[currIdx];

            if(isValid(length, forward) && !visited[forward]){
                if(arr[forward] == 0) return true;
                visited[forward] = true;
                q.push(forward);
            }

            if(isValid(length, backward) && !visited[backward]){
                if(arr[backward] == 0) return true;
                visited[backward] = true;
                q.push(backward);
            }
        }

        return false; 
    }
};

int main(){

}