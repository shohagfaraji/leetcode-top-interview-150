// https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 38.35%

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitFreq(32, 0);
        for (int& val : nums) {
            for (int i = 0; i < 32; i++) {
                if ((val & (1 << i))) {
                    bitFreq[i]++;
                }
            }
        }

        int single = 0;
        for (int i = 0; i < 32; i++) {
            if (bitFreq[i] % 3 == 1) {
                single |= (1 << i);
            }
        }
        return single;
    }
};
