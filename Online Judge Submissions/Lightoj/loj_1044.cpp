#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
string s;
ll dp[1005][1005], sub[1005][1005];
ll substring()
{
    memset(sub,0,sizeof(sub));
    ll i, j, k;
    for(i = 0; i < s.size(); i++){
        sub[i][i] = 1;
        for(j = i-1, k = i+1; j >= 0 and k < s.size() and s[j] == s[k]; j--, k++)
            sub[j][k] = 1;
        for(j = i, k = i+1; j >= 0 and k < s.size() and s[j] == s[k]; j--, k++)
            sub[j][k] = 1;
    }
}
ll f(ll from, ll to)
{
    if(from == s.size() and to == s.size()) return 0;
    if(to == s.size()) return inf;
    if(dp[from][to] != -1) return dp[from][to];
    ll a = inf, b;
    if(sub[from][to]) a = 1+f(to+1,to+1);
    b = f(from,to+1);
    return dp[from][to] = min(a,b);
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s;
        substring();
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,0));
    }
    return 0;
}
