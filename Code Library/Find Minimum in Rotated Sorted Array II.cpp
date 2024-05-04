/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
*/

class Solution {
private:
    int findStartPosition(vector<int>& nums){
        
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != nums.back()) return i;
        }
        
        return n - 1;
    }
    
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int lo = findStartPosition(nums), hi = n - 1;
        int result = nums.back();
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > nums.back()){
                lo = mid + 1;
            }
            else{
                result = mid;
                hi = mid - 1;
            }
        }
        return nums[result];
    }
};
