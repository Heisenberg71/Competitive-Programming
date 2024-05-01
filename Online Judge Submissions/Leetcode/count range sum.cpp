/*

Problem Link: https://leetcode.com/problems/count-of-range-sum/

*/

class Solution {
private:
    vector<long long> prefixSum;
    int lowerLimit, upperLimit;
    
    void merge(int start, int mid, int end){
        
        vector<long long> helper;
        
        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            if(prefixSum[i] < prefixSum[j]){
                helper.push_back(prefixSum[i++]);
            }
            else{
                helper.push_back(prefixSum[j++]);
            }
        }
        
        while(i <= mid){
            helper.push_back(prefixSum[i++]);
        }
        while(j <= end){
            helper.push_back(prefixSum[j++]);
        }
        
        for(int i = start, j = 0; i <= end; i++, j++){
            prefixSum[i] = helper[j];
        }
    }
    
    int mergeSort(int start, int end){
        
        if(start == end) return 0;
        
        int mid = start + (end - start)/2;
        int count = mergeSort(start, mid) + mergeSort(mid + 1, end);
        
        int lo = mid + 1, hi = mid + 1;
        
        for(int i = start; i <= mid; i++){
            while(lo <= end && prefixSum[lo] - prefixSum[i] < lowerLimit) lo++;
            while(hi <= end && prefixSum[hi] - prefixSum[i] <= upperLimit) hi++;
                
            count += (hi - lo);
        }
        
        merge(start, mid, end);
        
        return count;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        lowerLimit = lower, upperLimit = upper;
        prefixSum.push_back(0);
        for(auto& u: nums){
            prefixSum.push_back(prefixSum.back() + u);
        }
        
        return mergeSort(0, n);
    }
};
