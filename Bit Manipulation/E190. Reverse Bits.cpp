// https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 29.13%        Memory Beats: 44.11%

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & 1)
                ans |= (1 << i);
            n >>= 1;
        }
        return ans;
    }
};
