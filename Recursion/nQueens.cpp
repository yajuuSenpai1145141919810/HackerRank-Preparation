// Place N Cameras Without Conflict on Blocked Grid
// Given an NxN grid where 0 is empty and 1 is blocked, 
// return true if N cameras can be placed on empty cells such that no two share the same row, column, or diagonal.
// Input:N = 4, grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]], Output: True
// 人話就是八個皇后的問題啦 但有障礙物
bool dfs(int row, int N, vector<vector<int>>& grid,
         vector<bool>& col,
         vector<bool>& d1,
         vector<bool>& d2) {

    if (row == N) return true;

    for (int c = 0; c < N; c++) {
        if (grid[row][c] == 1) continue;

        int diag1 = row + c;
        int diag2 = row - c + N - 1;

       
        if (col[c] || d1[diag1] || d2[diag2]) continue;

     
        col[c] = true;
        d1[diag1] = true;
        d2[diag2] = true;

        if (dfs(row + 1, N, grid, col, d1, d2)) return true;

    
        col[c] = false;
        d1[diag1] = false;
        d2[diag2] = false;
    }

    return false;
}

bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {

    vector<bool> col(N, false);
    vector<bool> d1(2 * N - 1, false);
    vector<bool> d2(2 * N - 1, false);

    return dfs(0, N, grid, col, d1, d2);
}
