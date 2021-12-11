#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string s;
ll dp[10005][5][105], divi; //, dp2[15][5][5];
//ll f2(ll pos, ll issmall, ll num)
//{
//    if(pos == s[num].size()) return 1;
//    if(dp2[pos][issmall][num] != -1) return dp2[pos][issmall][num];
//    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
//    if(issmall) hi = 9;
//    for(; lo <= hi; lo++){
//        sum += f2(pos+1,issmall | (lo<hi), num);
//    }
//    return dp2[pos][issmall][num] = sum;
//}
ll f(ll pos, ll issmall, ll modsum)
{
    if(pos == s.size()){
        if(modsum == 0) return 1;
        return 0;
    }
    if(dp[pos][issmall][modsum] != -1) return dp[pos][issmall][modsum];
    ll lo = 0, hi = s[pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi), (modsum+lo)%divi);
        sum += tem;
        sum %= mod;
    }
    return dp[pos][issmall][modsum] = sum;
}
int main()
{
    cin >> s >> divi;
    memset(dp,-1,sizeof(dp));
    cout << (f(0,0,0)-1+mod)%mod << endl;
    return 0;
}
