#include <iostream>
#include <vector>
using namespace std;

int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1};

bool isValid(vector<vector<int>> &matrix, int r, int c){
    if(c >= matrix[0].size() || r >= matrix.size()){
        return false;
    }

    return true;
}

int grid_sum(vector<vector<int>> &matrix, int raw, int col){
    if(!isValid(matrix, raw, col)) {
        return 0;
    }

    int mx = INT_MIN;
    int max_raw = INT_MAX;
    int max_col = INT_MAX;

    for(int i = 0; i < 3; i++){
        int nr = raw + dr[i];
        int nc = col + dc[i];

        if(isValid(matrix, nr, nc) && matrix[nr][nc] > mx){
            mx = matrix[nr][nc];
            max_raw = nr;
            max_col = nc;
        }
    }

    return matrix[raw][col] + grid_sum(matrix, max_raw, max_col);
}


int main(){
    vector<vector<int>> grid = {{1, 7, 8}, {2, 10, 11}, {20, 5, 9}};
    cout << grid_sum(grid, 0, 0);
}