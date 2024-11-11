#include <iostream>
using namespace std;

int suffix_sum(int arr[], int len, int cnt){
    if(cnt == 0){
        return 0;
    }
    return arr[len - 1] + suffix_sum(arr, len - 1, cnt - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int cnt = 3;
    
    cout << "Suffix sum of last " << cnt << " elements: " << suffix_sum(arr, len, cnt) << endl;
    return 0;
}
