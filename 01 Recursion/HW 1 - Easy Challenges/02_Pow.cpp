#include <iostream>
using namespace std;

int my_pow(int value, int pow){
    if (pow == 0){
        return 1;
    }

    return value * my_pow(value, pow - 1);
}


int main(){
    cout << my_pow(2, 5);
}