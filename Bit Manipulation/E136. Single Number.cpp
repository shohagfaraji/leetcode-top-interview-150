// https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 83.27%

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int& val : nums) {
            single ^= val;
        }
        return single;
    }
};
