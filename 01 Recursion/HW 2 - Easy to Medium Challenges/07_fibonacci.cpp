#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> visited = {{1, 1}, {2, 1}};

int fibonacci(int n){
    if(visited.count(n)){
        return visited[n];
    }
    visited[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return visited[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
