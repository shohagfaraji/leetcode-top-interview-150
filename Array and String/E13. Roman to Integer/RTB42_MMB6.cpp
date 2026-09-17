// https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 42.09%        Memory Beats: 6.53%

class Solution {
public:
    map<char, int> roman = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
                            {'X', 10},   {'V', 5},   {'I', 1}};

    int romanToInt(string s) {
        map<char, char> maxToMin = {{'M', '0'}, {'D', '1'}, {'C', '2'},
                                    {'L', '3'}, {'X', '4'}, {'V', '5'},
                                    {'I', '6'}};
        string level = s;
        for (char& c : level) {
            c = maxToMin[c];
        }

        for (int i = s.size() - 2; i >= 0; i--) {
            level[i] = min(level[i], level[i + 1]);
        }

        int ans = 0, sign = -1;
        for (int i = 0; i < s.size(); i++) {
            sign = (maxToMin[s[i]] > level[i]) ? -1 : +1;
            ans += (sign * roman[s[i]]);
        }

        return ans;
    }
};
