#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int freqArr[100001] {0};
        int len = nums.size();

        for(int i = 0; i < len; i++){
            int idx = nums[i] + 50000;
            freqArr[idx]++;
        }

        int start = 0;
        for(int i = 0; i < 100001; i++){
            int num = i - 50000;
            while(freqArr[i]--){
                nums[start++] = num;
            }
        }

        return nums;
    }
};

int main(){
    
    return 0;
}