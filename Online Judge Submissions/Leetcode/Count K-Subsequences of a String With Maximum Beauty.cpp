/*

  Problem Link: https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/
  Time Complexity: O(NlogN)
  Space Complexity: O(NlogN)

*/
class Solution {
private:
    const static int MAX_CHAR_LIMIT = 26;
    const static int MOD = 1000000007;
    
    int bigmod(int a, int b){
        if(b == 0) return 1;
        int x = bigmod(a, b/2);
        x = ((long long)x*x) %MOD;
        if(b&1) x = ((long long)x*a) %MOD;
        return x;
    }
    
    int ncr(int n, int r){
        int fac_n = 1, fac_r = 1, fac_nr = 1;
        for(int i = 1; i <= n; i++){
            fac_n = ((long long)fac_n*i) %MOD;
            if(i == r) fac_r = fac_n;
            if(i == n - r) fac_nr = fac_n;
        }
        
        int numerator = fac_n;
        int denominator = ((long long)fac_r*fac_nr)%MOD;
        int result = (numerator*(long long)bigmod(denominator, MOD-2))%MOD;
        return ((long long)result+MOD)%MOD;
    }
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> charFreq(MAX_CHAR_LIMIT, 0);
        int distinct = 0;
        for(auto& ch: s){
            if(charFreq[ch - 'a'] == 0) distinct++;
            charFreq[ch - 'a']++;
        }
        
        if(distinct < k) return 0;
        
        unordered_map<int, int> charFreq_occur;
        for(int i = 0; i < MAX_CHAR_LIMIT; i++){
            if(charFreq[i] > 0) charFreq_occur[ charFreq[i] ]++;
        }
        
        vector<pair<int, int>> sorted_charFreq_occur;
        for(auto& x: charFreq_occur)
            sorted_charFreq_occur.push_back({x.first, x.second});
        sort(sorted_charFreq_occur.rbegin(), sorted_charFreq_occur.rend());
        
        long long maxSubStr = 1;
        for(auto& eachPair: sorted_charFreq_occur){
            if(eachPair.second <= k){
                maxSubStr = (maxSubStr*bigmod(eachPair.first, eachPair.second)) %MOD;
                k -= eachPair.second;
            }
            else{
                maxSubStr = (maxSubStr * ((ncr(eachPair.second, k) * (long long)bigmod(eachPair.first, k)) %MOD)) %MOD;
                break;
            }
        }
        
        return maxSubStr;
    }
};
