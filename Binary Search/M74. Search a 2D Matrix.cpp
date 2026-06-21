// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 78.50%

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
            cols = matrix[0].size(),
            l = 0, r = rows * cols - 1;
            
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / cols][mid % cols] < target)
                l = mid + 1;
            else
                r = mid;
        }

        return (matrix[r / cols][r % cols] == target);
    }
};