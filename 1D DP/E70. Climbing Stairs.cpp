// https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 68.66%

class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n <= 2)
            return dp[n] = n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = f(n - 1, dp) + f(n - 2, dp);
        
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(46, -1);
        return f(n, dp);
    }
};