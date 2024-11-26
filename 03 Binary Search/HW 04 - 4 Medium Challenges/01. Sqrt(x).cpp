// https://leetcode.com/problems/sqrtx/description/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;

        double start = 0;
        double end = x;
        double EPS = 1e-6;

        while(end - start > EPS){
            double mid = start + (end - start) / 2; 
            if(mid * mid - x == 0.0){
                return mid;
            }
            else if(mid * mid - x < 0.0){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        
        return start + EPS;
    }
};

int main(){

}