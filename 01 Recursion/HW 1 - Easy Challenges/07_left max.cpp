#include <iostream>
using namespace std;

void left_max(int arr[], int len){
    if(len == 0){
        return;
    }

    left_max(arr, len - 1);
    
    arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int main(){
    int arr[] = {1, 4, 5, 8, 10};
    left_max(arr, 5);
    for(int item: arr){
        cout << item << " ";
    }
}