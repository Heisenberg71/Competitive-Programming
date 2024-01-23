class Solution {
public:
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
}; 
..........................................................................................................................
class Solution {
private:
    int findLargestRectangle(int start, int finish, vector<int>& heights){
        if(start == finish) return heights[start];
        
        // cout << start << " " << finish << '\n';
        
        int mid = start + (finish - start)/2;
        int largestRectangleLeftSide = findLargestRectangle(start, mid, heights);
        int largestRectangleRightSide = findLargestRectangle(mid + 1, finish, heights);
        int largestRectangle = max(largestRectangleLeftSide, largestRectangleRightSide);
        
        int L = mid, R = mid + 1;
        int minHeight = min(heights[L], heights[R]);
        largestRectangle = max(largestRectangle, 2*minHeight);
        
        while(start < L || R < finish){
            if(start <= L - 1 && R + 1 <= finish){
                if(heights[L - 1] < heights[R + 1]){
                    minHeight = min(minHeight, heights[R + 1]);
                    R++;
                    largestRectangle = max(largestRectangle, (R - L + 1)*minHeight);
                }
                else{
                    minHeight = min(minHeight, heights[L - 1]);
                    L--;
                    largestRectangle = max(largestRectangle, (R - L + 1)*minHeight);
                }
            }
            else if(start <= L - 1){
                minHeight = min(minHeight, heights[L - 1]);
                L--;
                largestRectangle = max(largestRectangle, (R - L + 1)*minHeight);
            }
            else{
                minHeight = min(minHeight, heights[R + 1]);
                R++;
                largestRectangle = max(largestRectangle, (R - L + 1)*minHeight);
            }
        }
        
        return largestRectangle;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRectangleArea = findLargestRectangle(0, heights.size() - 1, heights);
        return largestRectangleArea;
    }
};
