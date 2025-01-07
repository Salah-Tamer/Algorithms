// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int operations = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                operations += i;
            }            
        }
        
        return operations;
    }
};

int main(){
    
}