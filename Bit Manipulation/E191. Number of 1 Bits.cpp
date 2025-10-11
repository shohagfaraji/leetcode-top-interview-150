// https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 80.94%

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};
