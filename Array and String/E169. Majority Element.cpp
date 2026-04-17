// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 27.80%

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for (int& ele : nums) {
            if (count == 0) {
                candidate = ele;
                count++;
                continue;
            }
            if (ele == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
