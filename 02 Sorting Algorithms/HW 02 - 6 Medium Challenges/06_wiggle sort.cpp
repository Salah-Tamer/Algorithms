#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void wiggleSort(vector<int> &nums){
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i + 1 < len; i++){
        swap(nums[i], nums[i + 1]);
    }
}

void wiggleSortII(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<int> ans;

    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        ans.push_back(nums[left]);
        if(left != right){
            ans.push_back(nums[right]);
        }

        left++;
        right--;
    }

    nums = ans;
}

int main(){
    vector<int> nums = {5, 1, 8, 6, 4, 3, 2, 7};
    wiggleSortII(nums);

    for(int num: nums){
        cout << num << " ";
    }
}