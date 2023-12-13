/*
    Problem Link: https://leetcode.com/problems/count-the-number-of-k-big-indices/description/
    T.C: O(NlogN)
    S.C: O(K)
*/

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> max_heap;
        vector<bool> has_less_than_k(n, false);
        for(int i = 0; i < n; i++){
            if(max_heap.size() == k && max_heap.top() < nums[i]){
                has_less_than_k[i] = true;
            }
            max_heap.push(nums[i]);
            if(max_heap.size() > k) max_heap.pop();
        }

        while(!max_heap.empty()) max_heap.pop();
        int k_big_indices = 0;
        for(int i = n - 1; i >= 0; i--){
            if(max_heap.size() == k && max_heap.top() < nums[i] && has_less_than_k[i]){
                k_big_indices++;
            }
            max_heap.push(nums[i]);
            if(max_heap.size() > k) max_heap.pop();
        }

        return k_big_indices;
    }
};
