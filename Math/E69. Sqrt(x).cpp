// https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 85.39%

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = 1e6;
        while (l <= r) {
            long long m = (l + r) / 2;
            if (m * m > x)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
};