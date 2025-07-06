// https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 42.08%

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<string> ans;
        int left = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 != nums[i]) {
                if (left == i - 1) {
                    ans.emplace_back(to_string(nums[left]));
                } else {
                    ans.emplace_back(to_string(nums[left]) + "->" +
                                     to_string(nums[i - 1]));
                }
                left = i;
            }
        }
        if (left == nums.size() - 1) {
            ans.push_back(to_string(nums[left]));
        } else {
            ans.push_back(to_string(nums[left]) + "->" +
                          to_string(nums.back()));
        }
        return ans;
    }
};