// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 91.13%

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (k % n == 0)
            return;

        k %= n;

        Reverse(nums, 0, n - 1);
        Reverse(nums, 0, k - 1);
        Reverse(nums, k, n - 1);
    }

    void Reverse(vector<int>& nums, int s, int e) {
        while (s < e) {
            swap(nums[s], nums[e]);
            s++, e--;
        }
    }
};