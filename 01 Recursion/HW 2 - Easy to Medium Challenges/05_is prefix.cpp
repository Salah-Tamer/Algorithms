#include <iostream>
#include <string>
using namespace std;

bool isPrefix(string main, string prefix, int start = 0){
    if(start == prefix.size()){
        return true;
    }
    if(main[start] != prefix[start]){
        return false;
    }
    return isPrefix(main, prefix, start + 1);
}

int main() {
    string mainStr = "hello";
    string prefix = "he";
    
    if (isPrefix(mainStr, prefix)) {
        cout << "\"" << prefix << "\" is a prefix of \"" << mainStr << "\"." << endl;
    } else {
        cout << "\"" << prefix << "\" is not a prefix of \"" << mainStr << "\"." << endl;
    }
    return 0;
}