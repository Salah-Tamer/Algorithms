#include <iostream>
using namespace std;

bool isPlindrome(int arr[], int len, int cnt = 0){
    if(len - 1 <= cnt){
        return true;
    }
    if(arr[len - 1] != arr[cnt]){
        return false;
    }
    return isPlindrome(arr, len - 1, cnt + 1);
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    if (isPlindrome(arr, len)) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }
    return 0;
}