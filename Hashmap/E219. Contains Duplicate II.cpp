// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 99.23%        Memory Beats: 29.99%

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end())
                if (i - hash[nums[i]] <= k)
                    return true;
            hash[nums[i]] = i;
        }

        return false;
    }
};