// Place N Cameras Without Conflict on Blocked Grid
// Given an NxN grid where 0 is empty and 1 is blocked, 
// return true if N cameras can be placed on empty cells such that no two share the same row, column, or diagonal.
// Input:N = 4, grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]], Output: True
// 人話就是八個皇后的問題啦 但有障礙物

// Diagonal: 右上到左下(0,2), (1,1), (2,0) 的和都是 2,左上到右下 (0,0), (1,1), (2,2) 的差都是 0。
// 在一個 4*4的棋盤中，有 14 條（7 條正向，7 條反向),就算以反對角線來看 只有一個點的(0,3),(3,3)也是 只是長度是一

// 流程如下:
// 如果適合就先放->去下一行探索->如果不合，就回去拆掉->如果到 col4 都不合，就 return false

bool dfs(int row, int N, vector<vector<int>>& grid, // row 現在做到哪一行, N就是大小
         vector<bool>& col,   // 記錄哪一欄已經放過相機了
         vector<bool>& d1,    // 正對角線：右上到左下,只要其中一個點被佔用，整條斜線就封鎖 
         vector<bool>& d2) {  // 反對角線：左上到右下 
         
    // 終止條件
    if (row == N) return true;

    for (int c = 0; c < N; c++) {
             
        // 這一格是空的嗎?
        if (grid[row][c] == 1) continue;
             
        // 右上到左下的斜線(0, 2), (1, 1), (2, 0),diag1 就編號為 2。
        int diag1 = row + c;
             
        // 左上到右下的斜線 
        int diag2 = row - c + N - 1;

        // 像是上面的(0, 2), (1, 1), (2, 0),diag1 就編號為 2 ,我這邊只要d1[2]就能直接把所有2的封鎖
        if (col[c] || d1[diag1] || d2[diag2]) continue;
         
        // 符合條件的話就放一個相機在這裡 並且把三個都設定true
        col[c] = true;
        d1[diag1] = true;
        d2[diag2] = true;
             
        // 下一排（row + 1）的人也去找個位置裝相機吧
        if (dfs(row + 1, N, grid, col, d1, d2)) return true;

        // 如果上面不行就放掉資源 
        col[c] = false;
        d1[diag1] = false;
        d2[diag2] = false;
    }

    return false;
}

bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {

    vector<bool> col(N, false);
    // 以 N=4 ：2*4-1=7 七條對角線
    vector<bool> d1(2 * N - 1, false);
    vector<bool> d2(2 * N - 1, false);

    return dfs(0, N, grid, col, d1, d2);
}
