ll fac[LIM];
ll bigmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = bigmod(a, b/2);
    x = (x*x)%mod;
    if(b%2 == 1) x = (x*a)%mod;
    return x;
}
void find_fac()
{
    ll i;
    for(i = 1, fac[0] = 1; i < LIM; i++)
        fac[i] = (i*fac[i-1])%mod;

}
ll ncr(ll n, ll r)
{
    ll up, down, ans;
    up = fac[n];
    down = (fac[r]*fac[n-r])%mod;
    ans = (up*bigmod(down, mod-2))%mod;
    return (ans+mod)%mod;
}
// add find_fac() in code
// add ncr() in code
