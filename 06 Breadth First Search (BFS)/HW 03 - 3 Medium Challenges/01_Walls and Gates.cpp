#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int Room = 2147483647;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool isValid(vector<vector<int>> &matrix, int r, int c){
    if(r < 0 || r >= matrix.size()){
        return false;
    }

    if(c < 0 || c >= matrix[0].size()){
        return false;
    }

    return true;
}

void bfs(vector<vector<int>> &matrix){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

    //find starting points (gates)
    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[0].size(); c++){
            if(!matrix[r][c]){ //gate
                q.push({r, c});
                visited[r][c] = true;
            }
        }
    }

    int level = 0;
    while(!q.empty()){
        int levelSize = q.size();

        while(levelSize--){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(!isValid(matrix, nr, nc) || visited[nr][nc] || matrix[nr][nc] == -1){
                    continue;
                }

                if(matrix[nr][nc] == Room){
                    matrix[nr][nc] = level + 1;
                }

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        level++;
    }
}

int main(){
    vector<vector<int>> rooms = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, 2147483647},
        {0, -1, 2147483647, 2147483647}
    };

    bfs(rooms);

    // Output the result
    for(const auto& row : rooms) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}