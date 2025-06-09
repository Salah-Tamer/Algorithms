#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> weight, value;
const int MAX = 2000 + 1;
int memory[MAX][MAX];

int knapsack(int idx, int remain){
    if(idx == weight.size()) return 0;

    auto &ret = memory[idx][remain];
    if(ret != -1) return ret;

    int leave = knapsack(idx + 1, remain);
    int pick = 0;

    if(remain >= weight[idx]){
        pick = value[idx] + knapsack(idx + 1, remain - weight[idx]);
    }

    return ret = max(pick, leave);
}

int main(){
    int max_weight, n;
    cin >> max_weight >> n;
    
    weight.resize(n);
    value.resize(n);

    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }

    memset(memory, -1, sizeof(memory));
    cout << knapsack(0, max_weight) << "\n";
    
    return 0;
}