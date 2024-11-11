#include <iostream>
#include <algorithm>
using namespace std;

void right_max(int arr[], int len, int start_position = 0){
    if (start_position == len - 1){
        return;
    }
    right_max(arr, len, start_position + 1);
    arr[start_position] = max(arr[start_position], arr[start_position + 1]);
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    right_max(arr, len);
    
    cout << "Array after applying right_max function: ";
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
