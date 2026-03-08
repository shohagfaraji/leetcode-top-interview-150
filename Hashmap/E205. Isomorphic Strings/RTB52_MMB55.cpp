// https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 52.64%        Memory Beats: 55.32%

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hashmap[2];
        
        for (int i = 0; i < s.size(); i++) {
            if (hashmap[0].find(s[i]) == hashmap[0].end()) {
                hashmap[0][s[i]] = t[i];
                hashmap[1][t[i]] = s[i];
                continue;
            }
            if (hashmap[0][s[i]] != t[i] || hashmap[1][t[i]] != s[i])
                return false;
        }

        return (hashmap[0].size() == hashmap[1].size());
    }
};
