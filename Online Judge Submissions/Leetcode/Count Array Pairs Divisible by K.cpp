/**
  Problem Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/
*/

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long pairsDivisibleByK = 0;
        unordered_map<int, int> divisiblePairs;
        for(auto& num: nums){
            int gcd = __gcd(num, k);
            int remaining = k/gcd;
            for(auto& divisiblePair: divisiblePairs){
                if(divisiblePair.first%remaining == 0)
                    pairsDivisibleByK += divisiblePair.second;
            }
            divisiblePairs[gcd]++;
        }
        return pairsDivisibleByK;
    }
};
