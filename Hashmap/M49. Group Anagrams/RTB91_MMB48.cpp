// https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 91.35%        Memory Beats: 48.74%

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        vector<int> freq(26, 0);
        auto f = [&](string& s) -> string {
            for (char& ch : s)
                freq[ch - 'a']++;

            string sorted = "";

            for (int i = 0; i < 26; i++) {
                sorted += string(freq[i], 'a' + i);
                freq[i] = 0;
            }

            return sorted;
        };

        for (int i = 0; i < strs.size(); i++)
            hash[f(strs[i])].emplace_back(strs[i]);

        vector<vector<string>> result;

        for (auto& [key, vec] : hash)
            result.emplace_back(vec);

        return result;
    }
};