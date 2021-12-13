#include <bits/stdc++.h>
#define ll long long
#define mod 10056
using namespace std;
ll dp[1005][1005], fact[1005];
ll s(ll n, ll k)
{
    if(dp[n][k] != -1) return dp[n][k];
    if(k == 1 or n == k) return 1;
    //if(n < k) return 0;
    return dp[n][k] = (s(n-1,k-1)%mod+(k*s(n-1,k))%mod)%mod;
}
void fac()
{
    fact[0] = 1;
    for(ll i = 1; i <= 1005; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }
}
int main()
{
    fac();
    ll t, n, i, cas = 1, ans;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin >> n;
        ans = 0;
        for(i = 1; i <= n; i++){ ///position
            ans += (s(n,i)*fact[i])%mod;
            ans %= mod;
        }
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
