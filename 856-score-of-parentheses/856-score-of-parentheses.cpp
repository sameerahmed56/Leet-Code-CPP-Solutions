class Solution {
public:
    int scoreOfParentheses(string s) {
        int cur = 0;
        stack<int> stack;
        for (char i : s)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
};
