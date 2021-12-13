#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll n, k, a[105], c[105], dp[110][1010];
ll f(ll in, ll rem)
{
    if(rem == 0) return 1;
    if(in >= n or rem < 0) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];

    ll ans = 0;
    for(ll i = 0; i <= c[in]; i++){
        ans += f(in+1,rem-i*a[in]);
        ans %= mod;
    }

    return dp[in][rem] = ans;
}
int main()
{
    ll t, cas = 1, i;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> c[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,k));
        //cout << f(0,k) << endl;
    }
    return 0;
}
