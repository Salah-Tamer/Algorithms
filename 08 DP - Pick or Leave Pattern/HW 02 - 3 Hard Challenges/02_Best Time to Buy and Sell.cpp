// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include <iostream>
#include <vector>
using namespace std;

const static int MAX = 5000 + 1;
int memory[MAX][2][3];
vector<int> _prices;

enum {
    NOTHING = 0, SELL = 1, BUY = 2
};

class Solution {
public:
    int trade(int idx, int have_stock, int last_transaction){
        if(idx >= _prices.size()){
            return 0;
        }

        auto &ret = memory[idx][have_stock][last_transaction];
        if(ret != -1){
            return ret;
        }

        int do_nothing = trade(idx + 1, have_stock, NOTHING);
        int sell = 0, buy = 0;

        if(have_stock){
            sell = _prices[idx] + trade(idx + 1, 0, SELL);
        } 
        else if(last_transaction != SELL){
            buy = -_prices[idx] + trade(idx + 1, 1, BUY);
        }

        return ret = max({do_nothing, sell, buy});
    }

    int maxProfit(vector<int>& prices) {
        _prices = prices;
        memset(memory, -1, sizeof(memory));
        return trade(0, 0, NOTHING);    
    }
};

int main(){
    return 0;
}