// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 46.83%

class Solution {
public:
    bool setBitMatch(int& left, int& right, int i) {
        return ((left & (1 << i)) && (right & (1 << i)));
    }

    bool firstNonMatch(int& left, int& right, int i) {
        return ((left & (1 << i)) != (right & (1 << i)));
    }

    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        bool notMatch = false;
        for (int i = 30; i >= 0; i--) {
            if (notMatch) {
                ans &= ~(1 << i);
                continue;
            }
            if (setBitMatch(left, right, i))
                ans |= (1 << i);
            if (firstNonMatch(left, right, i))
                notMatch = true;
        }
        return ans;
    }
};
