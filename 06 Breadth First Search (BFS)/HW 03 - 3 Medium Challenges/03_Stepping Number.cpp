#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool inrange(int num, long long low, long long high){
    if(num >= low && num <= high) return true;
    return false;
}

bool process(queue<long long> &q, vector<int> &answer, long long low, long long high, long long num){
    if(num > high){
        return false;
    }

    if(inrange(num, low, high)){
        answer.push_back(num);
    }

    q.push(num);
    return true;
}

vector<int> countSteppingNumbers(long long low, long long high){
    queue<long long> q;
    vector<int> answer;

    if(inrange(0, low, high)){
        answer.push_back(0);
    }

    for(int i = 1; i <= 9; i++){
        q.push(i);

        if(inrange(i, low, high)){
            answer.push_back(i);
        }
    }

    while(!q.empty()){
        int levelSize = q.size();
        while(levelSize--){
            long long num = q.front();
            q.pop();

            int last_digit = num % 10;
            if(last_digit != 0 && !process(q, answer, low, high, num * 10 + last_digit - 1)){
                break;
            }

            if(last_digit != 9 && !process(q, answer, low, high, num * 10 + last_digit + 1)){
                break;
            }
        }
    }

    return answer;
}

int main(){
    vector<int> result = countSteppingNumbers(0, 1000);
    for(int num : result){
        cout << num << " ";
    }
}