// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 96.91%

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;
        while (right != nums.size()) {
            if (sum < target) {
                sum += nums[right];
                right++;
            }
            if (sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        while (sum >= target) {
            ans = min(ans, right - left);
            sum -= nums[left];
            left++;
        }
        if (ans == INT_MAX) {
            ans = 0;
        }
        return ans;
    }
};