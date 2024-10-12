// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isPossible(vector<int>& bloomDay, int days, int m, int k) {
        int flowers = 0;
        int bouquets = 0; 

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++; 
                    flowers = 0; 
                }
            } else {
                flowers = 0; 
            }

            if (bouquets >= m) {
                return true; 
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len = bloomDay.size();
        if (len < (long) m * k) return -1; 

        int low = 0;
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(){

}