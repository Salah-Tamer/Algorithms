// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    static const int MAX = 2500 + 1;
    int memory[MAX][MAX];
    int len;
    vector<int> nums;
public:
    int LIS(int index, int prev){
        if(index == len) {
            return 0;
        }

        auto &ret = memory[index][prev];
        if(ret != -1){
            return ret;
        }

        int choice1 = LIS(index + 1, prev); // Leave
        int choice2 = 0;

        if(prev >= len || nums[prev] < nums[index]){
            choice2 = 1 + LIS(index + 1, index);
        }

        return ret = max(choice1, choice2);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        this->nums = nums;
        len = nums.size();
        memset(memory, -1, sizeof(memory));
        return LIS(0, len);
    }
};

int main(){

}