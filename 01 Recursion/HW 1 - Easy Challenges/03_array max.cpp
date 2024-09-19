#include <iostream>
using namespace std;

int arr_max(int arr[], int len){
    if(len == 1){
        return arr[0];
    }

    return max(arr_max(arr, len - 1), arr[len - 1]);
}

int main(){
    int arr[] = {1, 5, 4, 8, 10};
    cout << arr_max(arr, 5);
}