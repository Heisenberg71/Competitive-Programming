#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[5];
ll dp[15][5][5][5], dp2[15][5][5];
ll f2(ll pos, ll issmall, ll num)
{
    if(pos == s[num].size()) return 1;
    if(dp2[pos][issmall][num] != -1) return dp2[pos][issmall][num];
    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        sum += f2(pos+1,issmall | (lo<hi), num);
    }
    return dp2[pos][issmall][num] = sum;
}
ll f(ll pos, ll issmall, ll hasstarted, ll num)
{
    if(pos == s[num].size()) return 0;
    if(dp[pos][issmall][hasstarted][num] != -1) return dp[pos][issmall][hasstarted][num];
    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi), hasstarted | (lo != 0), num);
        if(hasstarted and lo == 0) tem += f2(pos+1,issmall | (lo<hi),num);
        sum += tem;
    }
    return dp[pos][issmall][hasstarted][num] = sum;
}
int main()
{
    ll t, cas = 1, mm, nn;
    cin >> t;
    while(t--){
        cin >> mm >> nn;
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
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        ll x = f(0,0,0,1);
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        ll y = f(0,0,0,0);
        printf("Case %lld: %lld\n", cas++, x-y+ff);
       //cout << s[0] << " " << s[1] << endl;
       //cout << x << endl;
        s[0].clear(); s[1].clear();
    }
    return 0;
}
