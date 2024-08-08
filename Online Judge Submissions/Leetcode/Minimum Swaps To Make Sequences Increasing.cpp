class Solution {
private:
    vector<vector<int>> dp;
    int n;
    int findMinSwaps(int index, int prevState, vector<int>& nums1, vector<int>& nums2) {
        if(index == n) return 0;
        int& ret = dp[index][prevState];
        if(ret != -1) return ret;

        ret = INT_MAX/2;
        if(prevState == 0){
            if(index == 0 || nums1[index - 1] < nums1[index] && nums2[index - 1] < nums2[index]) 
                ret = findMinSwaps(index + 1, 0, nums1, nums2);
            if(index == 0 || nums1[index - 1] < nums2[index] && nums2[index - 1] < nums1[index])
                ret = min(ret, 1 + findMinSwaps(index + 1, 1, nums1, nums2));
        }
        else{
            if(index == 0 || nums2[index - 1] < nums1[index] && nums1[index - 1] < nums2[index])
                ret = findMinSwaps(index + 1, 0, nums1, nums2);
            if(index == 0 || nums1[index - 1] < nums1[index] && nums2[index - 1] < nums2[index])
                ret = min(ret, 1 + findMinSwaps(index + 1, 1, nums1, nums2));
        }

        return ret;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.assign(n, vector<int>(2, -1));
        return findMinSwaps(0, 0, nums1, nums2);
    }
};
