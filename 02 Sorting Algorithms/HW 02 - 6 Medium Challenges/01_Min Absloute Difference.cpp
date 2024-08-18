// https://leetcode.com/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        int len = arr.size();

        for(int i = 1; i < len; i++){
            int diff = min(diff, arr[i] - arr[i - 1]);
        }

        for(int i = 1; i < len; i++){
            int diff = arr[i] - arr[i - 1];
            if(diff == minDiff){
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;

    }
};