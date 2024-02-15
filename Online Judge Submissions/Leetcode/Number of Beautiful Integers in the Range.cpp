/*
    Problem Link: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/
*/
class Solution {
private:
    int INVALID = -1;
    int dp[15][2][20][20][2];
    int K;
    int fun(int pos, int isSmall, int reminder, int evenOddDiff, int hasStarted, string& str){
        if(pos == str.size()){
            return (evenOddDiff == 10 && reminder == 0);
        }
        
        int& ret = dp[pos][isSmall][reminder][evenOddDiff][hasStarted];
        if(ret != INVALID) return ret;
        
        int upperLimit = (isSmall) ? 9 : str[pos] - '0';
        ret = 0;
        for(int d = 0; d <= upperLimit; d++){
            int x = (d&1) ? 1 : -1;
            if(d > 0) hasStarted = 1;
            if(hasStarted == 0) x = 0;
            ret += fun(pos + 1, (isSmall | (d < upperLimit)), (reminder*10 + d)%K, evenOddDiff + x, hasStarted, str);
        }
        
        return ret;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string lowStr, highStr;
        low--;
        K = k;
        while(low){
            lowStr.push_back((char)('0' + low%10));
            low /= 10;
        }
        while(high){
            highStr.push_back((char)('0' + high%10));
            high /= 10;
        }
 
        while(lowStr.size() < highStr.size())
            lowStr.push_back('0');
        
        reverse(lowStr.begin(), lowStr.end());
        reverse(highStr.begin(), highStr.end());
        
        memset(dp, INVALID, sizeof dp);
        int x = fun(0, 0, 0, 10, 0, highStr);
        memset(dp, INVALID, sizeof dp);
        int y = fun(0, 0, 0, 10, 0, lowStr);
        
        return x - y;
    }
};
