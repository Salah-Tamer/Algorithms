#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX; int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(k && nums[i] < 0){
                nums[i] = -nums[i];
                k--;
            }

            sum += nums[i];
            mn = min(mn, nums[i]);
        }

        if(k % 2) {
            sum -= 2 * mn;
        }

        return sum;
    }
};