// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrivalTime;
        for(int i = 0; i < dist.size(); i++){
            arrivalTime.push_back( (float) dist[i] / speed[i]);
        }

        sort(arrivalTime.begin(), arrivalTime.end());

        int maxM = 0;
        for(int i = 0; i < arrivalTime.size(); i++){
            if(arrivalTime[i] <= i){
                break;
            }
            maxM++;
        }

        return maxM;
    }
};

int main(){
    vector<int> dist = {1,3,4};
    vector<int> speed = {1,1,1};
    Solution solution;
    solution.eliminateMaximum(dist, speed);
}