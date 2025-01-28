// https://leetcode.com/problems/sliding-puzzle/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        string target = "123450";
        string startState;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;
        while (!queue.empty()) {
            int size = queue.size();
            while (size--) {
                string currentState = queue.front();
                queue.pop();

                if (currentState == target) {
                    return moves;
                }

                int zeroPos = currentState.find('0');
                for (int newPos : directions[zeroPos]) {
                    string newState = currentState;
                    swap(newState[zeroPos], newState[newPos]);

                    if (visited.count(newState)) continue;

                    visited.insert(newState);
                    queue.push(newState);
                }
            }
            moves++;
        }
        return -1;
    }
};

int main(){

}