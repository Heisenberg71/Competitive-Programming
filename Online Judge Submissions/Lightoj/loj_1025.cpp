#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll dp[105][105];
ll f(ll L, ll R)
{
    if(L == R) return 1;
    if(L > R) return 0;
    if(dp[L][R] != -1) return dp[L][R];
    if(s[L] == s[R]) return dp[L][R] = 1 + f(L+1,R) + f(L,R-1);
    else return dp[L][R] = f(L+1,R) + f(L,R-1) - f(L+1,R-1);
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s;
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,s.size()-1));
    }
    return 0;
}
