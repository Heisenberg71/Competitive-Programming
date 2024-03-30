/*
https://leetcode.com/problems/maximum-score-of-spliced-array/
*/

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sumOfElementsNums1 = 0, numOfElementsNums2 = 0;
        for(auto& u: nums1)
            sumOfElementsNums1 += u;
        for(auto& u: nums2)
            numOfElementsNums2 += u;
        
        int maxNums1 = 0, maxNums2 = 0;
        int sumNums1 = 0, sumNums2 = 0;
        int maxAns = max(sumOfElementsNums1, numOfElementsNums2);
        
        for(int i = 0; i < n; i++){
            sumNums1 += (nums2[i] - nums1[i]);
            sumNums2 += (nums1[i] - nums2[i]);
            
            if(sumNums1 < 0) sumNums1 = 0;
            if(sumNums2 < 0) sumNums2 = 0;
            
            maxNums1 = max(maxNums1, sumNums1);
            maxNums2 = max(maxNums2, sumNums2);
        }
        
        maxAns = max(maxAns, max(sumOfElementsNums1 + maxNums1, numOfElementsNums2 + maxNums2));
        return maxAns;
    }
};
