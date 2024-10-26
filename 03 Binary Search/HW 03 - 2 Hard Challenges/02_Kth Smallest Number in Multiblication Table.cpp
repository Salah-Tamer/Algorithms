// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int count_leq(int rows, int cols, int k, int val){
        int count = 0;
        for(int r  = 1; r <= rows; r++){
            // Count how many numbers in row `r` are <= `val`
            // `val / r` tells us the biggest column we can reach in this row
            // Use `min(val / r, cols)` to stay within the number of columns
            count += min(val / r, cols);
        }

        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int start = 1, end = m * n, kth = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(count_leq(m, n, k, mid) < k){
                start = mid + 1;
            }
            else{
                end = mid - 1;
                kth = mid;
            }
        }

        return kth;
    }
};

int main(){

}