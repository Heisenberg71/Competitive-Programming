/*
Problem Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
*/

class Solution {
private:
    vector<int> smallerAfterSelf, indexOf, temp, tempIdx;
    
    void mergeSort(int start, int end, vector<int>& nums){
        if(start >= end) return;
        
        int mid = start + (end - start)/2;
        mergeSort(start, mid, nums);
        mergeSort(mid + 1, end, nums);
        
        int i = start, j = mid + 1, k = start, smaller = 0;
        while(i <= mid && j <= end){
            if(nums[i] > nums[j]){
                temp[k] = nums[j];
                tempIdx[k] = indexOf[j];
                smaller++;
                j++;
            }
            else{
                temp[k] = nums[i];
                tempIdx[k] = indexOf[i];
                smallerAfterSelf[ indexOf[i] ] += smaller;
                i++;
            }
            k++;
        }
        
        while(i <= mid){
            temp[k] = nums[i]; 
            tempIdx[k] = indexOf[i];
            smallerAfterSelf[ indexOf[i] ] += smaller;
            i++; k++;
        }
        
        while(j <= end){
            temp[k] = nums[j];
            tempIdx[k] = indexOf[j];
            j++; k++;
        }
        
        for(int i = start; i <= end; i++){
            nums[i] = temp[i];
            indexOf[i] = tempIdx[i]; 
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        smallerAfterSelf.assign(n, 0);
        indexOf.assign(n, 0);
        temp.assign(n, 0);
        tempIdx.assign(n, 0);
        
        for(int i = 0; i < n; i++)
            indexOf[i] = i;
        
        mergeSort(0, n - 1, nums);
        
        return smallerAfterSelf;
    }
};
