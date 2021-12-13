#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll dp[40][5][5], dp2[40][5];
ll f2(ll pos, ll issmall)
{
    if(pos == s.size()) return 1;
    if(dp2[pos][issmall] != -1) return dp2[pos][issmall];
    ll lo = 0, hi = s[pos]-'0', sum = 0;
    if(issmall) hi = 1;
    for(; lo <= hi; lo++){
        sum += f2(pos+1,issmall | (lo<hi));
    }
    return dp2[pos][issmall] = sum;
}
ll f(ll pos, ll issmall, ll prev)
{
    if(pos == s.size()) return 0;
    if(dp[pos][issmall][prev] != -1) return dp[pos][issmall][prev];
    ll lo = 0, hi = s[pos]-'0', sum = 0;
    if(issmall) hi = 1;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi), lo);
        if(prev == 1 and lo == 1) tem += f2(pos+1,issmall | (lo<hi));
        sum += tem;
    }
    return dp[pos][issmall][prev] = sum;
}
int main()
{
    ll t, n, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        while(n){
            s += n%2 + '0';
            n /= 2;
        }
        reverse(s.begin(),s.end());
        //cout << s << endl;
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        printf("Case %lld: %lld\n", cas++, f(0,0,0));
        s.clear();
    }
    return 0;
}
