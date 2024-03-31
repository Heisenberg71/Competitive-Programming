/*
    https://leetcode.com/problems/longest-valid-parentheses/
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int longestValidParenthesesLength = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
                continue;
            }
            stk.pop();
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            longestValidParenthesesLength = 
                max(longestValidParenthesesLength, i - stk.top());
        }
        return longestValidParenthesesLength;
    }
};
