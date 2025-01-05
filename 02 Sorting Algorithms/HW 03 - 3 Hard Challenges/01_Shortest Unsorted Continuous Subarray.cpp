// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        // Find the first index where the current element is greater than the next element
        while (start < n - 1 && nums[start] <= nums[start + 1]) {
            start++;
        }

        // If the array is already sorted
        if (start == n - 1) {
            return 0;
        }

        // Find the last index where the current element is less than the previous element
        while (end > 0 && nums[end] >= nums[end - 1]) {
            end--;
        }

        // Find the minimum and maximum values in the unsorted subarray
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int i = start; i <= end; i++) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }

        // Expand the start to the left if there are elements greater than the minimum value
        while (start > 0 && nums[start - 1] > min_val) {
            start--;
        }

        // Expand the end to the right if there are elements less than the maximum value
        while (end < n - 1 && nums[end + 1] < max_val) {
            end++;
        }

        return end - start + 1;
    }
};

int main(){
    
}