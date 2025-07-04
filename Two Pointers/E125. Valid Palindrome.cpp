// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 47.54%        Memory Beats: 58.24%

class Solution {
    bool isAlpha(char& c) {
        if ('0' <= c && c <= '9')
            return true;
        if ('a' <= c && c <= 'z')
            return true;
        if ('A' <= c && c <= 'Z') {
            c = c + ' ';
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            i += (!isAlpha(s[i]));
            j -= (!isAlpha(s[j]));
            if (isAlpha(s[i]) && isAlpha(s[j])) {
                if (s[i] != s[j])
                    return false;
                i++, j--;
            }
        }
        return true;
    }
};