class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int reminder = 0;
        for(auto& x: nums)
            reminder = (reminder + x) %p;
        
        if(reminder == 0) return 0; 
            
        unordered_map<int, int> modedSum_lastIndex;
        modedSum_lastIndex[0] = -1;
        int prefixReminder = 0, minAns = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            prefixReminder = (prefixReminder + nums[i]) %p;
            int x = (prefixReminder - reminder + p) %p;
            if(modedSum_lastIndex.count(x)) minAns = min(minAns, i - modedSum_lastIndex[x]);
            modedSum_lastIndex[prefixReminder] = i;
        }
        
        return (minAns == nums.size()) ? -1 : minAns;
    }
};
