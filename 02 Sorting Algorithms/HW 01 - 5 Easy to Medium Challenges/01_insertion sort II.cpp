#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums){
    int len = nums.size();
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0 && nums[j] < nums[j - 1]; j--){
            swap(nums[j], nums[j - 1]);
        }
    }
}

int main(){
    vector<int> nums = {17, 16, 10, 5, 9, 18, 2};
    insertionSort(nums);

    for(int &num: nums){
        cout << num << " ";
    }
}