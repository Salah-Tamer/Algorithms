#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {100000495, 100000490, 100000497, 100000492, 100000499};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int len = nums.size();

    //find min and max value
    for(int i = 0; i < len; i++){
        if(nums[i] < minVal) {
            minVal = nums[i];
        }

        if(nums[i] > maxVal){
            maxVal = nums[i];
        }
    }

    int range = maxVal - minVal;
    vector<int> freq(range + 1, 0);

    for(int i = 0; i < len; i++){
        freq[nums[i] - minVal]++;
    }

    int start = 0;
    for(int i = 0; i < range + 1; i++){
        while(freq[i]--){
            nums[start++] = i + minVal;
        }
    }

}