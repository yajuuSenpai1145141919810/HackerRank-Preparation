// Place N Cameras Without Conflict on Blocked Grid
// Given an NxN grid where 0 is empty and 1 is blocked, 
// return true if N cameras can be placed on empty cells such that no two share the same row, column, or diagonal.
// Input:N = 4, grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]], Output: True
// 人話就是八個皇后的問題啦 但有障礙物

// Diagonal: 右上到左下(0,2), (1,1), (2,0) 的和都是 2,左上到右下 (0,0), (1,1), (2,2) 的差都是 0。
// 在一個 4*4的棋盤中，有 14 條（7 條正向，7 條反向）

bool dfs(int row, int N, vector<vector<int>>& grid, // row 現在做到哪一行, N就是大小
         vector<bool>& col,   // 記錄哪一欄已經放過相機了
         vector<bool>& d1,    // 正對角線：右上到左下,只要其中一個點被佔用，整條斜線就封鎖 
         vector<bool>& d2) {  // 反對角線：左上到右下 
         
    // 終止條件
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
