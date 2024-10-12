// https://leetcode.com/problems/heaters/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool isPossible(vector<int> &houses, vector<int> &heaters, int radius) {
        int currHouse = 0;

        for(int i = 0; i < heaters.size(); i++){
            int left = heaters[i] - radius, right = heaters[i] + radius;

            while(currHouse < houses.size() && houses[currHouse] >= left && houses[currHouse] <= right){
                currHouse++;
            }
        }

        return currHouse == houses.size(); // all are covered? 
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int low = 0; 
        int high = max(houses[houses.size() - 1], heaters[heaters.size() - 1]); 

        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(houses, heaters, mid)) {
                ans = mid; // Save the last valid radius
                high = mid - 1; // Try for a smaller radius
            } else {
                low = mid + 1; // Increase the radius
            }
        }

        return ans;
    }
};

int main(){

}