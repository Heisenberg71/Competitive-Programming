#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf (1<<30)
#define LIM 300005
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector <ll> pos, val;
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
int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    find_fac();

    ll t, cas = 1, n, k, i, x, y;
    cin >> t;
    while(t--){
        cin >> n >> k;
        pos.pb(0), val.pb(1);
        for(i = 0; i < k; i++){
            cin >> x >> y;
            pos.pb(x+1), val.pb(y);
        }
        pos.pb(n+1), val.pb(n);
        ll ans = 1;
        for(i = 1; i < pos.size(); i++){
            ll gap = pos[i]-pos[i-1]-1;
            ll range = val[i]-val[i-1];
            ans *= ncr(range+gap, gap);
            ans %= mod;
        }
        printf("Case %lld: %lld\n", cas++, ans);
        pos.clear(), val.clear();
    }



    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/

