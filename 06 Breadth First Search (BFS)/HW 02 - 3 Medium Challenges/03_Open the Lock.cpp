// https://leetcode.com/problems/open-the-lock

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
	char next(char c) {
		if (c == '9'){
			return '0';
        }
		return c + 1;
	}
	
	char prev(char c) {
		if (c == '0'){
			return '9';
        }
		return c - 1;
	}
public:
	int openLock(vector<string> &deadends, string target) {
        string start = "0000";
		unordered_set<string> visited { deadends.begin(), deadends.end() };
		queue<string> q;

        if(visited.count(start)){
            return -1;  
        }

        if(start == target){
            return 0;  
        }

		q.push(start);
		visited.insert(start);
        int level = 0;

		while(!q.empty()) {
            int levelSize = q.size();

			while (levelSize--) {
				string cur = q.front();
				q.pop();
				
                //try to turn each wheel
				for (int i = 0; i < 4; i++) {
					cur[i] = next(cur[i]); // move forward
					
                    if (cur == target){
						return level + 1;
                    }

					if (visited.insert(cur).second){
						q.push(cur);
                    }

					cur[i] = prev(prev(cur[i]));	//undo forward and move backward

					if (cur == target){
						return level + 1;
                    }

					if (visited.insert(cur).second){
						q.push(cur);
                    }

					cur[i] = next(cur[i]);	//undo backward and move to reset
				}
			}

            level++;
		}
		return -1;
	}
};

int main(){

}