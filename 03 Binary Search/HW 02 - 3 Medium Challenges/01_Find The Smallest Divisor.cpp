// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool isPossible(vector<int> &nums, int divisor, int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double) nums[i] / divisor);
        }

        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int len = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums, mid, threshold)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low  = mid + 1;
            }
        }

        return ans;
    }
};

int main(){

}