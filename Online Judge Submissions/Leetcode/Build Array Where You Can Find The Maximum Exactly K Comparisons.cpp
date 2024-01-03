/*

Problem Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

*/

class Solution {
private:
    int INVALID = -1;
    const static int MOD = 1000000007;
    vector<vector<vector<int>>> dp;
    int M;
    int findWays(int currPos, int cost, int largestValue){
        if(cost < 0) return 0;
        if(currPos == 0) return (cost == 0);
        
        int& ret = dp[currPos][cost][largestValue];
        if(ret != INVALID) return ret;
        
        ret = (1LL*largestValue*findWays(currPos - 1, cost, largestValue)) %MOD;
        if(cost == 0) return ret;
        for(int i = largestValue + 1; i <= M; i++){
            ret = (ret + findWays(currPos - 1, cost - 1, i)) %MOD;
        }
        
        return ret;
    }
    
public:
    int numOfArrays(int n, int m, int k) {
        dp.assign(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, INVALID)));
        M = m;
        return findWays(n, k, 0);
    }
};
