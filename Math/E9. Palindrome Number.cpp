// https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 32.53%        Memory Beats: 14.87%

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = to_string(x);
        int n = s.size();
        for (int i = 0; i + i < n; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};