// https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 69.58%

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string tempWord = "";
        map<char, string> charToWord;
        map<string, bool> duplicateCheck;
        int i, j, wordCount = 0;

        for (i = j = 0; i < pattern.size(); i++) {
            tempWord = "";
            while (j < s.size()) {
                if (s[j] == ' ') {
                    j++;
                    break;
                }
                tempWord += s[j];
                j++;
            }

            if (tempWord != "")
                wordCount++;
            else
                break;

            if (charToWord.find(pattern[i]) != charToWord.end()) {
                if (charToWord[pattern[i]] == tempWord)
                    continue;
                else
                    return false;
            } else {
                if (duplicateCheck[tempWord])
                    return false;
                charToWord[pattern[i]] = tempWord;
                duplicateCheck[tempWord] = true;
            }
        }

        return (pattern.size() == wordCount && j == s.size());
    }
};
