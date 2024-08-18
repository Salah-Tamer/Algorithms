#include <iostream>
#include <vector>
#include <string>
using namespace std;

void countSort(vector<string> &names) {
    vector<vector<string>> freq(676); 
    int len = names.size();

    for(int i = len - 1; i >= 0; i--){
        int idx = (names[i][0] - 'a') * 26 + (names[i][1] - 'a');
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
    vector<string> names = {"axz", "axa", "zzz", "abc", "abe"};
    countSort(names);

    for(const string name: names){
        cout << name << " ";
    }

}