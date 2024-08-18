// https://leetcode.com/problems/array-partition/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int maxSum = 0; 


        for(int i = 0; i < len; i += 2){
            maxSum += nums[i];
        }

        return maxSum;
    }
};