#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[2];
ll dp[11][2][95][95][2], divi;
ll f(ll pos, ll issmall, ll modsum, ll digsum, ll num)
{
    if(pos == s[num].size()){
        if(modsum == 0 and digsum == 0) return 1;
        return 0;
    }
    if(dp[pos][issmall][modsum][digsum][num] != -1) return dp[pos][issmall][modsum][digsum][num];
    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi), (10*modsum+lo)%divi, (digsum+lo)%divi, num);
        sum += tem;
    }
    return dp[pos][issmall][modsum][digsum][num] = sum;
}
int main()
{
    ll t, cas = 1, mm, nn;
    cin >> t;
    while(t--){
        cin >> mm >> nn >> divi;
        ll ff = 0;
        if(mm == 0) ff = 1;
        if(mm < 2) s[0] += '0';
        else{
            mm--;
            while(mm){
                s[0] += mm%10 + '0';
                mm /= 10;
            }
        }
        if(nn == 0) s[1] += '0';
        else{
            while(nn){
            s[1] += nn%10 + '0';
            nn /= 10;
        }
        }
        reverse(s[0].begin(),s[0].end());
        reverse(s[1].begin(),s[1].end());
        if(divi > 90){
            printf("Case %lld: 0\n", cas++);
        }
        else{
            memset(dp,-1,sizeof(dp));
            ll x = f(0,0,0,0,1);
            memset(dp,-1,sizeof(dp));
            ll y = f(0,0,0,0,0);
            printf("Case %lld: %lld\n", cas++, x-y+ff);
        }
        s[0].clear(); s[1].clear();
    }
    return 0;
}
