#include <iostream>
using namespace std;

void arr_increment(int arr[], int len){
    if (len == 0){
        return;
    }

    arr_increment(arr, len - 1);
    arr[len - 1] += len - 1;
} 

int main(){
    int arr[] = {1, 4, 5, 9, 6, 10};
    arr_increment(arr, 6);
    for(int item : arr){
        cout << item << " ";
    }
}