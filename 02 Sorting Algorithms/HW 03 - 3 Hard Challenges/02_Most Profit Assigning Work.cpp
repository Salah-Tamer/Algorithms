// https://leetcode.com/problems/most-profit-assigning-work/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> assignment;
        int result = 0;

        for(int i = 0; i < n; i++){
            int diff = difficulty[i];
            int prof = profit[i];
            assignment.push_back({prof, diff});
        }

        sort(assignment.begin(), assignment.end());
        sort(worker.begin(), worker.end());

        int workerIdx = worker.size() - 1;
        int assignmentIdx = n - 1;
        while(assignmentIdx >= 0 && workerIdx >= 0){
            int diff = assignment[assignmentIdx].second;
            if(diff > worker[workerIdx]){
                assignmentIdx--;
            }
            else{
                result += assignment[assignmentIdx].first;
                workerIdx--;
            }
        }

        return result;
    }
};

int main(){

}