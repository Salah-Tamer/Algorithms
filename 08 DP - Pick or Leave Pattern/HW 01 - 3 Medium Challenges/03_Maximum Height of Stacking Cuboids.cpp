// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
    vector<vector<int>> cuboidsg;
    const static int MAX = 100 + 1;
    int memory[MAX][MAX];

    bool less_eq(int i, int j){
        return cuboidsg[i][1] <= cuboidsg[j][1] && cuboidsg[i][2] <= cuboidsg[j][2];
    }

    int LIS(int curr, int prev){
        if(curr == cuboidsg.size()) {
            return 0;
        }

        auto &ret = memory[curr][prev];
        if(ret != -1) {
            return ret;
        }

        int choice1 = LIS(curr + 1, prev);    //Leave
        int choice2 = 0;

        if(prev == cuboidsg.size() || less_eq(prev, curr)){
            choice2 = cuboidsg[curr][2] + LIS(curr + 1, curr); //Pick
        }

        return ret = max(choice1, choice2);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c : cuboids){
            sort(c.begin(), c.end());
        }

        sort(cuboids.begin(), cuboids.end());
        
        cuboidsg = cuboids;
        memset(memory, -1, sizeof(memory));
        return LIS(0, cuboids.size());
    }
};

int main(){
    return 0;
}