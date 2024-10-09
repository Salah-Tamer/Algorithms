// https://leetcode.com/problems/find-right-interval/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int Search(vector<vector<int>>& intervals, int target){
        int l = 0;
        int h = intervals.size() - 1;
        int position = -1;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(intervals[mid][0] < target){
                l = mid + 1;
            }
            else if(intervals[mid][0] >= target){
                position = mid;
                h = mid - 1;
            }
        }

        return position;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<vector<int>> startings;
        for(int i = 0; i < intervals.size(); i++){
            startings.push_back({intervals[i][0], i});
        }
        sort(startings.begin(), startings.end());

        vector<int> res(len, -1);
        for(int i = 0; i < intervals.size(); i++){
            int idx = Search(startings, intervals[i][1]);
            if(idx != -1){
                res[i] = startings[idx][1];
            }
        }

        return res;   
    }
};

int main(){
    
}