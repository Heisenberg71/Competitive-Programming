*/
https://leetcode.com/problems/burst-balloons/
*/

class Solution {
private:
    vector<vector<int>> dp;
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        int n = nums.size();
        dp.assign(n, vector<int>(n, 0));
        
        for(int len = 1; len <= n - 2; len++){
            for(int L = 1, R = len; R + 1 < n; L++, R++){
                for(int i = L; i <= R; i++){
                    int make = nums[L - 1] * nums[R + 1] * nums[i];
                    int plus = dp[L][i - 1] + dp[i + 1][R]; 
                    dp[L][R] = max(dp[L][R], make + plus);
                }
            }
        }
        
        return dp[1][n - 2];
    }
};
