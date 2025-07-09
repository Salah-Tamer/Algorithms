#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 500;
const int MAX_T = 700;
int memory[MAX_N][MAX_T];
vector<int> nums;

bool canSubsetSum(int idx, int target){
    if(target < 0) return false;
    if(target == 0) return true;
    if(idx == nums.size()) return 0;

    auto &ret = memory[idx][target];
    if(ret != -1) {
        return ret;
    }

    // Leave
    if(canSubsetSum(idx + 1, target)){
        return ret = true;
    }

    // Pick
    return ret = canSubsetSum(idx + 1, target - nums[idx]);
} 

bool subsetSum(vector<int> &values, int target){
    nums = values;
    memset(memory, -1, sizeof(memory));
    return canSubsetSum(0, target);
}

int main(){
    vector<int> values = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << (subsetSum(values, target) ? "YES" : "NO") << endl;
    return 0;
}