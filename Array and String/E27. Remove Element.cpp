// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 11.95%

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, k = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[k] != val) {
                k++;
                continue;
            }
            if (nums[i] != val) {
                swap(nums[k], nums[i]);
                k++;
            }
        }
        
        i = k = 0;
        while (i < nums.size()) {
            if (nums[i] != val)
                k++;
            else
                break;
            i++;
        }
        return k;
    }
};
