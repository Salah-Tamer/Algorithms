#include <iostream>
#include <vector>
#include <string>
using namespace std;

void countSort(vector<string> &names) {
    vector<vector<string>> freq(26); 
    int len = names.size();

    for(int i = len - 1; i >= 0; i--){
        int idx = names[i][0] - 'a';
        freq[idx].push_back(names[i]);
    }

    int start = 0;
    for(int i = 0; i < 26; i++){
        while(!freq[i].empty()){
            names[start++] = freq[i].back(); 
            freq[i].pop_back(); 
        }
    }
}

int main(){
    vector<string> names = {"ziad", "belal", "adam", "baheir", "ali"};
    countSort(names);

    for(const string name: names){
        cout << name << " ";
    }

}