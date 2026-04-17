// https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 67.31%

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int lengthOfLastWord = 0;

        while (i >= 0) {
            if (isalpha(s[i]))
                lengthOfLastWord++;
            else if (lengthOfLastWord > 0)
                break;
            i--;
        }

        return lengthOfLastWord;
    }
};
