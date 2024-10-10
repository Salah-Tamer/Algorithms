#include <iostream>
using namespace std;

class Solution {
    bool isPossible(int n, long rows){
        long sum = (rows * (rows + 1)) / 2;
        return n >= sum;
    }
public:
    int arrangeCoins(int n) {
        int low = 0, high = n, answer = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(n, mid)){
                low = mid + 1;
                answer = mid;
            }
            else{
                high = mid - 1;
            }
        } 

        return answer;
    }
};

int main(){

}