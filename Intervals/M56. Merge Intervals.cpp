// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 82.06%

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        
        sort(intervals.begin(), intervals.end());

        while (i < n) {
            if (i && result.back()[1] >= intervals[i][1]) {
                i++;
                continue;
            }

            result.emplace_back(intervals[i++]);

            while (i < n) {
                if (intervals[i][0] - result.back()[1] > 0)
                    break;

                result.back()[1] = max(result.back()[1], intervals[i][1]);
                i++;
            }
        }

        return result;
    }
};
