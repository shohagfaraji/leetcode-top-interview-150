// https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 83.48%        Memory Beats: 79.33%

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for(string &str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hash[temp].emplace_back(str);
        }

        vector<vector<string>> result;

        for (auto& [key, vec] : hash)
            result.emplace_back(vec);

        return result;
    }
};