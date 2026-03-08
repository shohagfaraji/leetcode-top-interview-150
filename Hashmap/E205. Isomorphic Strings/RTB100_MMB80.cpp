// https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 80.70%

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(128, 0);
        vector<int> indexT(128, 0);

        for (int i = 0; i < s.size(); i++) {
            if (indexS[s[i]] != indexT[t[i]])
                return false;
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }

        return true;
    }
};
