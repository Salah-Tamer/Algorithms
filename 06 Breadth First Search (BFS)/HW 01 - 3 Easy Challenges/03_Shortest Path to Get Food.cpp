#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

vector<vector<bool>> visited;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool isValid(vector<vector<char>> &grid, int r, int c){
    if(r < 0 || r >= grid.size()) return false;
    if(c < 0 || c >= grid[0].size()) return false;

    return true;
}

int bfs(vector<vector<char>> &grid, int r, int c){
    queue<pair<int, int>> q;
    int count = 0; // count the shortest number of steps

    q.push({r, c});
    visited[r][c] = 1;

    while (!q.empty()) {
        int levelSize = q.size();  

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            pair<int, int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

    
            if (grid[r][c] == '#') {
                return count;  // Found the food, return the number of steps
            }

            // Explore neighbors
            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (isValid(grid, nr, nc) && grid[nr][nc] != 'X' && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;  // Mark as visited
                }
            }
        }

        // After processing all nodes at the current level, increment the count (steps)
        count++;
    }

    return -1;
}

int main(){
    vector<vector<char>> grid = {
        {'X','X','X','X','X','X'},
        {'X','*','O','O','O','X'},
        {'X','O','O','#','O','X'},
        {'X','X','X','X','X','X'}
    };

    visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    for(int r = 0; r < grid.size(); r++){
        for(int c = 0; c < grid[r].size(); c++){
            if(grid[r][c] == '*'){
                cout << bfs(grid, r, c);
            }
        }
    }
}