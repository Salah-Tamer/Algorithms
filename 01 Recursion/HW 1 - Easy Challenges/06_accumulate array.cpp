#include <iostream>
using namespace std;

void accumulate_arr(int arr[], int len){
    if(len == 0){
        return;
    }

    accumulate_arr(arr, len - 1);
    arr[len - 1] += arr[len - 2];
}

int main(){
    int arr[] = {1, 4, 6, 8, 10};
    accumulate_arr(arr, 5);
    for(int item: arr){
        cout << item << " ";
    }
}