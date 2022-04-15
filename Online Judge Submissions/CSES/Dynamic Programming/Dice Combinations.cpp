#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 1000006
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

ll n, dp[LIM];

ll fun(ll pos){
    if(pos > n) return 0;
    if(pos == n) return 1;
    if(dp[pos] != -1) return dp[pos];

    ll ans = 0;
    for(ll i = 1; i <= 6; i++){
        ans += fun(pos + i);
        ans %= mod;
    }

    return dp[pos] = ans;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << fun(0) << nl;


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
