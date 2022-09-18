#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

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

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    find_fac();

    ll t, d, k;
    cin >> t;
    while(t--){
        cin >> d >> k;

        if(d%2 == 1){
            cout << 0 << nl;
            continue;
        }

        ll ans = 0;
        for(ll x = d; x + x > d; x--){
//            cout << "sf" << nl;
//            cout << d - x << " " << k - 1 << " " << bigmod(d - x, k - 1) << nl;
            ans = ((ans + (((ncr(d, x)*k) %mod)*bigmod(k - 1, d - x)) %mod) %mod + mod) %mod;
        }
//        cout << "ans: " << bigmod(k, d) << " " << ans << nl;
        cout << ((bigmod(k, d) - ans) %mod + mod) %mod << nl;
    }

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. READ PROBLEM STATEMENT CAREFULLY.
    2. LOOK SPECIAL CASE (LIKE, N = 1).
    3. LOOK FOR OVERFLOW.
    4. LOOK FOR OUT OF BOUNDS.
    5. DO NOT STUCK WITH A SINGLE APPROACH.
    6. THINK OUT OF THE BOX.
**/
