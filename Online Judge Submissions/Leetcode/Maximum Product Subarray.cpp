/*
Problem Name: Maximum Product Subarray
Problem Link: https://leetcode.com/problems/maximum-product-subarray/
Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProduct_L = 1, prefixProduct_R = 1, max_product = INT_MIN;
        bool firstNeg = false;
        for(int L = 0, R = 0; R < nums.size(); R++){
            max_product = max(max_product, nums[R]);
            if(nums[R] == 0){
                prefixProduct_L = prefixProduct_R = 1;
                L = R + 1;
                firstNeg = false;
                continue;
            }
            prefixProduct_R *= nums[R];
            
            if(prefixProduct_R < 0){
                if(firstNeg == false){
                    firstNeg = true;
                    while(nums[L] > 0){
                        prefixProduct_L *= nums[L];
                        L++;
                    }
                    prefixProduct_L *= nums[L]; L++;
                }
                if(L < R) max_product = max(max_product, prefixProduct_R/prefixProduct_L);
            }
            else max_product = max(max_product, prefixProduct_R);
            
            
        }
        return max_product;
    }
};
