// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;  
            if (nums[mid] == target) {
                ans[0] = mid;
                h = mid - 1;  
            }
            else if (target < nums[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                l = mid + 1;  
            }
            else if (target < nums[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};

int main(){

}