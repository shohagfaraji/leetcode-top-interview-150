// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 5.07%        Memory Beats: 100.00%

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size(), j = 0;
        for(int i = 1 ; i < n ; i++){
            if(v[i] != v[j]) {
                j++;
                v[j] = v[i];
            }
        }
        return ++j;
    }
};
