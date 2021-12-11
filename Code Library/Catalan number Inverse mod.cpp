#define ll long long   /// MACRO NEEDED
#define LIM 300005     /// MACRO NEEDED
#define mod 1000000007 /// MACRO NEEDED

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
        fac[i] = (i*fac[i-1])%mod;  /// factorial generation upto LIM
}
ll ncr(ll n, ll r)
{
    ll up, down, ans;
    up = fac[n];
    down = (fac[r]*fac[n-r])%mod;
    ans = (up*bigmod(down, mod-2))%mod;  /// modular multiplicative inverse
    return (ans+mod)%mod;
}
ll cat(ll n)
{
    ll down;
    down = bigmod(n+1,mod-2);     /// modular multiplicative inverse        
    return (ncr(2*n,n)*down+mod)%mod;   /// catalan[i] = (1/(i+1))*(2*i)Ci
}

/// fac();        NEED TO CALL THE FUNCTION FROM MAIN
/// val = cal()   NEED TO CALL THE FUNCTION FROM MAIN
