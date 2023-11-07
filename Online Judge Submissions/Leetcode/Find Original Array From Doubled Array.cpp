/*

  Problem Link: https://leetcode.com/problems/find-original-array-from-doubled-array/
  Time Complexity: O(NlogN)
  Space Complexity: O(N)

  Here, 
  N = number of element

*/


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> freq;
        for(auto& x: changed) freq[x]++;
        sort(changed.begin(), changed.end());
        vector<int> original;
        for(auto& x: changed){
            if((x == 0 && freq[x] >= 2) || (x != 0 && freq[x] && freq[x + x])){
                freq[x]--, freq[x + x]--;
                original.push_back(x);
            }
        }
        if(original.size()*2 == changed.size()) return original;
        return {};
    }
};
