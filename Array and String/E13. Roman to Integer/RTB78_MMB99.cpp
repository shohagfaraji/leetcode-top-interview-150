// https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 78.65%        Memory Beats: 99.16%

class Solution {
private:
    int romToDec(char& ch) {
        switch (ch) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
        }
    }

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int val = romToDec(s[i]);
            if ((i + 1 < n) && (val < romToDec(s[i + 1])))
                ans -= val;
            else
                ans += val;
        }

        return ans;
    }
};