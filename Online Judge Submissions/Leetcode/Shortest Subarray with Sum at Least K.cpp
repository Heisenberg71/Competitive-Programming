/*
    Problem Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefixSum;
        prefixSum.push_back(0);
        
        for(auto& u: nums){
            prefixSum.push_back(prefixSum.back() + u);
        }

        deque<int> monotonicDeque;
        int n = nums.size() + 1;
        int shortestSubArrayLength = n;
        for(int i = 0; i < n; i++){
            while(!monotonicDeque.empty() && prefixSum[i] <= prefixSum[ monotonicDeque.back() ]){
                monotonicDeque.pop_back();
            }
            while(!monotonicDeque.empty() && prefixSum[i] >= prefixSum[ monotonicDeque.front() ] + k){
                shortestSubArrayLength = min(shortestSubArrayLength, i - monotonicDeque.front());
                monotonicDeque.pop_front();
            }
            monotonicDeque.push_back(i);
        }

        return (shortestSubArrayLength < n) ? shortestSubArrayLength : -1;
    }
};
