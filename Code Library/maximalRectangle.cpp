/*
Problem Link: https://leetcode.com/problems/maximal-rectangle/
*/


class Solution {
private:
    void makePrefixSumOfAllColumns(vector<vector<char>>& matrix, vector<vector<int>>&columnPrefixSumOfMatrix){
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++){
            columnPrefixSumOfMatrix[i][0] = (matrix[i][0] == '1');
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == '0') continue;
                columnPrefixSumOfMatrix[i][j] = columnPrefixSumOfMatrix[i][j - 1] + (matrix[i][j] == '1');
            }
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> columnPrefixSumOfMatrix(row, vector<int>(col, 0));
        makePrefixSumOfAllColumns(matrix, columnPrefixSumOfMatrix);
        
        int maxRectangle = 0;
        for(int i = 0; i < col; i++){
            vector<int> eachRow;
            for(int j = 0; j < row; j++){
                eachRow.push_back(columnPrefixSumOfMatrix[j][i]);
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(eachRow));
        }
        
        return maxRectangle;
    }
};
