// https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 36.00%

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];

            if (mp.find(temp) != mp.end())
                return {mp[temp], i};
            
            mp[nums[i]] = i;
        }

        return {};
    }
};
