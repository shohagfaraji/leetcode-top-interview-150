// https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 83.57%

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
                continue;
            }
            if (stk.empty())
                return false;
            if (c == ')') {
                if (stk.top() != '(')
                    return false;
                stk.pop();
            } else if (c == '}') {
                if (stk.top() != '{')
                    return false;
                stk.pop();
            } else {
                if (stk.top() != '[')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};