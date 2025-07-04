// https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 82.96%

class Solution {
public:
    int boxNo(int& i, int& j) {
        if (i >= 0 && i <= 2) {
            if (j >= 0 && j <= 2)
                return 0;
            if (j >= 3 && j <= 5)
                return 1;
            return 2;
        } else if (i >= 3 && i <= 5) {
            if (j >= 0 && j <= 2)
                return 3;
            if (j >= 3 && j <= 5)
                return 4;
            return 5;
        } else {
            if (j >= 0 && j <= 2)
                return 6;
            if (j >= 3 && j <= 5)
                return 7;
            return 8;
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> row(9, 0);
        vector<bitset<9>> col(9, 0);
        vector<bitset<9>> box(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int val = board[i][j] - '1';
                    if (row[i][val]) {
                        return false;
                    } else {
                        row[i][val] = 1;
                    }
                    if (col[j][val]) {
                        return false;
                    } else {
                        col[j][val] = 1;
                    }
                    if (box[boxNo(i, j)][val]) {
                        return false;
                    } else {
                        box[boxNo(i, j)][val] = 1;
                    }
                }
            }
        }
        return true;
    }
};