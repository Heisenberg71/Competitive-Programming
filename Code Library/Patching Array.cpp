class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int minPatchesNeeded = 0, i = 0;
        while(sum < n) {
            if(i < nums.size() &&  nums[i] <= sum + 1){
                sum += nums[i];
                i++;
            }
            else{
                sum += sum + 1;
                minPatchesNeeded++;
            }
        }
        return minPatchesNeeded;
    }
};
