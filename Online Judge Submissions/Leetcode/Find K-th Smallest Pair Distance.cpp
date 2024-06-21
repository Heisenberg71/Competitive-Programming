class Solution {
private:
    const static int MAX_VALUE = 1000000;

    bool exist_atleast_k_elements_smaller_than_mid(int value, vector<int>& nums, int k){

        int L = 0, R = 0, total = 0;
        while(L < nums.size()){
            while(R < nums.size() && nums[R] - nums[L] <= value) R++;
            total += R - L - 1;
            L++;
            if(R < L) R = L;
        }

        return (total >= k);
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int kthSmallest;
        int lo = 0, hi = MAX_VALUE;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(exist_atleast_k_elements_smaller_than_mid(mid, nums, k)){
                kthSmallest = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return kthSmallest;
    }
};
