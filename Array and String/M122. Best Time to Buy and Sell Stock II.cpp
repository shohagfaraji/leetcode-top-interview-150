// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 63.56%

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int mxProf = 0, n = prices.size();
        int mn = prices[0];

        for (int i = 1; i + 1 < n; i++) {
            if (prices[i - 1] <= prices[i] && prices[i] >= prices[i + 1]) {
                mxProf += (prices[i] - mn);
                mn = prices[i + 1];
            }
            mn = min(mn, prices[i]);
        }

        if (n > 1 && prices[n - 2] < prices[n - 1]) {
            mxProf += (prices[n - 1] - mn);
        }

        return mxProf;
    }
};