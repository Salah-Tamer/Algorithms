#include <iostream>
using namespace std;

int prefix_sum(int arr[], int cnt){
    if(cnt == 0){
        return 0;
    }
    return arr[cnt - 1] + prefix_sum(arr, cnt - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int cnt = 3;
    
    cout << "Prefix sum of first " << cnt << " elements: " << prefix_sum(arr, cnt) << endl;
    return 0;
}