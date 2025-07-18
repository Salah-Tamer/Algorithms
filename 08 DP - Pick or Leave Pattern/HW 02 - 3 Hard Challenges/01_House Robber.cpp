// https://leetcode.com/problems/house-robber/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> numbers;
    const static int MAX = 100 + 1;
    int memory[MAX];
    
    int getMaxAmount(int idx){
        if(idx >= numbers.size()) return 0;
        auto &ret = memory[idx];
        if(ret != -1) return ret;

        int choice1 = getMaxAmount(idx + 1); //Leave
        int choice2 = numbers[idx] + getMaxAmount(idx + 2); //Pick

        return ret = max(choice1, choice2);
    }
public:
    int rob(vector<int>& nums) {
        numbers = nums;
        memset(memory, -1, sizeof(memory));
        return getMaxAmount(0);
    }
};

int main(){
    return 0;
}