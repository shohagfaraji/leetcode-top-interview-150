// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 84.28%        Memory Beats: 89.53%

class Solution {
public:
    void dfs(int i, int j, int& m, int& n, vector<vector<char>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i - 1, j, m, n, grid);
        dfs(i, j - 1, m, n, grid);
        dfs(i + 1, j, m, n, grid);
        dfs(i, j + 1, m, n, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')
                    continue;
                dfs(i, j, m, n, grid);
                islands++;
            }
        }
        return islands;
    }
};