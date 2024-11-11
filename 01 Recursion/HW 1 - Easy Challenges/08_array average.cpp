#include <iostream>
#include <vector>
using namespace std;


double arr_average(vector<int> &arr, int len, int i = 0){
    if(i == len) return 0;
    double avr = (double) arr[i] / (double) len;
    return avr + arr_average(arr, len, i + 1);
}

int main(){
    vector<int> nums = {5, 3, 4, 1};
    cout << arr_average(nums, 4);
}