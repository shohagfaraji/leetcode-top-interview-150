// https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 47.10%

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);

        for (char& c : s)
            freq[c - 'a']++;

        for (char& c : t)
            freq[c - 'a']--;

        for (int& cnt : freq)
            if (cnt != 0)
                return false;

        return true;
    }
};