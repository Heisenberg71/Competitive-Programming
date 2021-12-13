#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll hitpoints[16+5], n, dp[1<<16+5];
string grid[16];
bool check(ll pos, ll mask) {return (mask&(1<<pos));}
ll mark(ll pos, ll mask) {return (mask|(1<<pos)); }
ll maxi(ll pos, ll mask)
{
    ll mx = 1, i;
    for(i = 0; i < n; i++){
        ll tem = grid[i][pos]-'0';
        if(check(i,mask)) mx = max(mx,tem);
    }
    return mx;
}
ll f(ll mask)
{
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    ll ans = inf, i;
    for(i = 0; i < n; i++){
        if(!check(i,mask)){
            ll mx = maxi(i,mask);
            ans = min(ans,(hitpoints[i]+mx-1)/mx + f(mark(i,mask)));
        }
    }
    return dp[mask] = ans;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> hitpoints[i];
        for(i = 0; i < n; i++)
            cin >> grid[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0));
    }
    return 0;
}
