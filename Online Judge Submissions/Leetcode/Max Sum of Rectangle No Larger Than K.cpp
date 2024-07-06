class Solution {
private:
    int maxLengthSubArraySumLessThanK(vector<int>& subMatrix, int k) {
        set<int> accuSet;
        accuSet.insert(0);
        int curSum = 0, curMax = INT_MIN;
        for (int sum : subMatrix) {
            curSum += sum;
            set<int>::iterator it = accuSet.lower_bound(curSum - k);
            if (it != accuSet.end())
                curMax = std::max(curMax, curSum - *it);
            accuSet.insert(curSum);
        }
        return curMax;
    }

    int maxSumSubArrayForFixedWeidth(int startCol, int endCol,
                                     vector<vector<int>>& matrix, int k) {
        vector<int> subMatrix;
        for (int i = 0; i < matrix.size(); i++) {
            int rowSum = (startCol == 0)
                             ? matrix[i][endCol]
                             : matrix[i][endCol] - matrix[i][startCol - 1];
            subMatrix.push_back(rowSum);
        }

        return maxLengthSubArraySumLessThanK(subMatrix, k);
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rowSize = matrix.size(), colSize = matrix[0].size();
        for (int L = 0; L < rowSize; L++) {
            int sum = 0;
            for (int R = 0; R < colSize; R++) {
                matrix[L][R] =
                    (R == 0) ? matrix[L][R] : matrix[L][R - 1] + matrix[L][R];
            }
        }

        int maxSumSubMatrix = INT_MIN;
        for (int L = 0; L < colSize; L++) {
            for (int R = L; R < colSize; R++) {
                maxSumSubMatrix =
                    max(maxSumSubMatrix,
                        maxSumSubArrayForFixedWeidth(L, R, matrix, k));
            }
        }

        return maxSumSubMatrix;
    }
};
