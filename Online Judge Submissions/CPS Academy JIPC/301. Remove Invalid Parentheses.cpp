class Solution {
private:
    int minimumRemoved;
    unordered_set<string> validExpressions;
    void backtrack(string& s, int currentIndex, int leftCount, int rightCount, string& expression, int removedCount) {

        if(currentIndex == s.size()) {
            if(leftCount != rightCount || removedCount > minimumRemoved) {
                return;
            }
            if(removedCount < minimumRemoved) {
                validExpressions.clear();
                minimumRemoved = removedCount;
            }
            validExpressions.insert(expression);
            return;
        }

        char currentChar = s[currentIndex];
        if(currentChar != '(' && currentChar != ')') { // currentChar is an alphabet
            expression.push_back(currentChar);
            backtrack(s, currentIndex + 1, leftCount, rightCount, expression, removedCount);
            expression.pop_back();
            return;
        }

        // currentChar is an openning or closing bracket

        // not include
        backtrack(s, currentIndex + 1, leftCount, rightCount, expression, removedCount + 1);

        // include
        expression.push_back(currentChar);
        if(currentChar == '(') {
            backtrack(s, currentIndex + 1, leftCount + 1, rightCount, expression, removedCount);
        }
        else if(rightCount + 1 <= leftCount) {
            backtrack(s, currentIndex + 1, leftCount, rightCount + 1, expression, removedCount);
        }
        expression.pop_back();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        string expression = "";
        minimumRemoved = s.size();
        backtrack(s, 0, 0, 0, expression, 0);
        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};
