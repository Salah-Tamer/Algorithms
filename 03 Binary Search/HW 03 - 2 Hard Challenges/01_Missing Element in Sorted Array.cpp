#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// O(n) solution
int kth_missing(vector<int> &nums, int k){
    int len = nums.size();
    unordered_set<int> original_nums(nums.begin(), nums.end());

    int start = nums[0];
    int end = nums[len - 1];

    while(start <= end){
        if(!original_nums.count(start)){
            k--;

            if(k == 0) return start;
        }

        start++;
    }

    return -1;

}

class Solution{
    int missing(int idx, vector<int> &nums){
        return nums[idx] - nums[0] + idx;
    }

    int kth(int idx, vector<int> &nums, int k){
        return nums[idx] + k - missing(idx, nums);
    }

    //O(log n)
    int missingElement(vector<int> &nums, int k){
        int n = nums.size();
        if(k > missing(n - 1, nums)){
            return kth(n - 1, nums, k);
        }

        int start = 0, end = n - 1, lower_bound = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(missing(mid, nums) < k){
                start = mid + 1;
            }
            else{
                end = mid - 1, lower_bound = mid;
            }
        }

        return kth(lower_bound, nums, k);
    }
};

int main(){
    vector<int> nums = {4, 7, 9, 10};
    cout << kth_missing(nums, 3);
}