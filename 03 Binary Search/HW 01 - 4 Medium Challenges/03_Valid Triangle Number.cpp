// https://leetcode.com/problems/valid-triangle-number/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    //lower bound: find the first greater than of equal index
    int BinarySearch(vector<int> &nums, int start, int target){
        int end = nums.size() - 1;
        int position = nums.size();

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target){
                position = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return position;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                int k = j + 1;

                int first_idx = BinarySearch(nums, k, nums[i] + nums[j]);
                count += first_idx - j - 1;
            }
        }

        return count;
    }
};

int main(){

}