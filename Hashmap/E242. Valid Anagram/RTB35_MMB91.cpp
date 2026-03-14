// https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 35.72%        Memory Beats: 91.29%

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};
