// https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 60.58%

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() != 9) {
            digits.back()++;
            return digits;
        }

        int n = digits.size() - 1;

        while (n >= 0) {
            if (digits[n] != 9) {
                digits[n]++;
                return digits;
            }
            digits[n] = 0;
            n--;
        }

        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }
};