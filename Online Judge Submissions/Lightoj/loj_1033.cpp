#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s;
ll dp[105][105];
ll f(ll l, ll r)
{
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll a = inf, b = inf;
    if(s[l] == s[r]) a = f(l+1,r-1);
    else b = 1 + min(f(l+1,r),f(l,r-1));
    return dp[l][r] = min(a,b);
}
int main()
{
    ll n, i, cas = 1;
    cin >> n;
    while(n--){
        cin >> s;
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,s.size()-1));
    }
    return 0;
}
