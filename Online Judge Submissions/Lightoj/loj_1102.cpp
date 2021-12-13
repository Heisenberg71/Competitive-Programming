#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll fact[2000005]; /// need to increase before submit
void fac()
{
    fact[0] = 1;
    for(ll i = 1; i < 2000005; i++){ /// here also
        fact[i] = i*fact[i-1];
        fact[i] %= mod;
    }
}
ll bigmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = bigmod(a,b/2);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}
int main()
{
    fac();
    ll t, n, k, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll up = fact[n+k-1];
        ll down = (fact[n]*fact[k-1])%mod;
        printf("Case %lld: %lld\n", cas++, (up*bigmod(down,mod-2))%mod);
    }
    return 0;
}
