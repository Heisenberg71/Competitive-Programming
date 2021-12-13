#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0) return 1;
    ll x = bigmod(a,b/2,mod);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}
int main()
{
    ll n, loop, mod, t, cas = 1, val, i, x, ans;
    cin >> t;
    while(t--){
        cin >> n >> loop >> mod;
        for(i = val = 0; i < n; i++){
            cin >> x;
            val += x;
            val %= mod;
        }
        ans = bigmod(n,loop-1,mod);
        ans = (ans*loop)%mod;
        ans = (ans*val)%mod;
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
