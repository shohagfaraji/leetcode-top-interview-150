// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 76.06%        Memory Beats: 59.41%

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int indx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (indx < 2 || nums[i] != nums[indx - 2]) {
                nums[indx] = nums[i];
                indx++;
            }
        }

        return indx;
    }
};