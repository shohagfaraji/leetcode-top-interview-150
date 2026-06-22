// https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 69.12%

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() - 1;
        int m = board[0].size() - 1;

        bitset<200> vis[200];

        auto dfs = [&](auto&& self, int i, int j) -> void {
            vis[i][j] = 1;

            if (i - 1 >= 0 && board[i - 1][j] == 'O' && !vis[i - 1][j])
                self(self, i - 1, j);

            if (i + 1 <= n && board[i + 1][j] == 'O' && !vis[i + 1][j])
                self(self, i + 1, j);

            if (j - 1 >= 0 && board[i][j - 1] == 'O' && !vis[i][j - 1])
                self(self, i, j - 1);

            if (j + 1 <= m && board[i][j + 1] == 'O' && !vis[i][j + 1])
                self(self, i, j + 1);
        };

        for (int i = 0; i <= m; i++) {
            if (board[0][i] == 'O' && !vis[0][i])
                dfs(dfs, 0, i);

            if (board[n][i] == 'O' && !vis[n][i])
                dfs(dfs, n, i);
        }

        for (int i = 1; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(dfs, i, 0);

            if (board[i][m] == 'O' && !vis[i][m])
                dfs(dfs, i, m);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};