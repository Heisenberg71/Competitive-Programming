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


// Space complexity: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        int longestValidParenthesesLength = 0;
        for(auto& u: s){
            if(u == '(') leftCount++;
            else rightCount++;

            if(leftCount == rightCount) longestValidParenthesesLength = 
                max(longestValidParenthesesLength, leftCount + rightCount);
            if(leftCount < rightCount) leftCount = rightCount = 0;
        }

        leftCount = 0, rightCount = 0;
        for(int i = s.size() - 1; i >= 0;  i--){
            if(s[i] == ')') rightCount++;
            else leftCount++;

            if(leftCount == rightCount) longestValidParenthesesLength = 
                max(longestValidParenthesesLength, leftCount + rightCount);
            if(leftCount > rightCount) leftCount = rightCount = 0;
        }

        return longestValidParenthesesLength;
    }
};
