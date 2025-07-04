// https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 75.48%

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for (char& c : magazine) {
            freq[c - 'a']++;
        }
        for (char& c : ransomNote) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};