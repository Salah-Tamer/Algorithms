#include <iostream>
using namespace std;

int print_3n_plus_1(int num){
    if(num == 1)
        return 1;
    if(num % 2 == 0){
        return 1 + print_3n_plus_1(num / 2);
    }

    return 1 + print_3n_plus_1(3 * num + 1);
}

int main(){
    cout << print_3n_plus_1(5);
}