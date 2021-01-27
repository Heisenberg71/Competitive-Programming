ll fac[LIM];
 
void find_fac()
 
{
    ll i;
    for(i = 1, fac[0] = 1; i <= LIM; i++)
        fac[i] = (i*fac[i-1])%mod;
 
}
 
ll bigmod(ll a, ll b)
 
{
    if(b == 0) return 1;
    ll x = bigmod(a, b/2);
    x = (x*x)%mod;
    if(b%2 == 1) x = (x*a)%mod;
    return x;
}
 
int main()
{
    ll n, r, t, i, up, down, ans;
    find_fac();
    cin >> t;
    for(i = 0; i < t; i++){
        cin >> n >> r;
        up = fac[n];
        down = (fac[r]*fac[n-r])%mod;
        ans = (up*bigmod(down, mod-2))%mod;
        printf("Case %lld: %lld\n", i+1, ans);
    }
 
    return 0;
}
