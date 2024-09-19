#include <iostream>
using namespace std;

int arr_sum(int arr[], int len){
    if(len == 1){
        return arr[0];
    }

    return arr[len - 1] + arr_sum(arr, len - 1);
}


int main(){
    int arr[] = {1, 5, 4, 8, 6, 10};
    cout << arr_sum(arr, 6);
}