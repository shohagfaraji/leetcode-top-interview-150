// https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 60.41%

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int i, int j,
             bitset<200> (&vis)[200]) {
        vis[i][j] = 1;

        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !vis[i - 1][j])
            dfs(board, i - 1, j, vis);

        if (i + 1 <= n && board[i + 1][j] == 'O' && !vis[i + 1][j])
            dfs(board, i + 1, j, vis);

        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !vis[i][j - 1])
            dfs(board, i, j - 1, vis);

        if (j + 1 <= m && board[i][j + 1] == 'O' && !vis[i][j + 1])
            dfs(board, i, j + 1, vis);
    }

    void solve(vector<vector<char>>& board) {
        bitset<200> vis[200];

        n = board.size() - 1;
        m = board[0].size() - 1;

        for (int i = 0; i <= m; i++) {
            if (board[0][i] == 'O' && !vis[0][i])
                dfs(board, 0, i, vis);
            if (board[n][i] == 'O' && !vis[n][i])
                dfs(board, n, i, vis);
        }

        for (int i = 1; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(board, i, 0, vis);
            if (board[i][m] == 'O' && !vis[i][m])
                dfs(board, i, m, vis);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
