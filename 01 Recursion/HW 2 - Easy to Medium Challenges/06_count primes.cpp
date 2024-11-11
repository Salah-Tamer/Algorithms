#include <iostream>
#include <unordered_map>
using namespace std;

bool isPrime(int val, int start = 3){
    if(val == start || val == 2){
        return true;
    }
    if(val % start == 0 || val <= 1){
        return false;
    }
    return isPrime(val, start + 1);
}

int countPrimes(int start, int end){
    if(start > end){
        return 0;
    }
    int res = isPrime(start);
    return res += countPrimes(start + 1, end);
}

int main() {
    int start = 10, end = 20;
    cout << "Count of primes between " << start << " and " << end << ": " << countPrimes(start, end) << endl;
    return 0;
}