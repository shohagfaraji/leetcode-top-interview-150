// https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 16.89%

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSum = nums[0];
        int curSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curSum = max(nums[i], curSum + nums[i]);
            mxSum = max(mxSum, curSum);
        }
        return mxSum;
    }
};