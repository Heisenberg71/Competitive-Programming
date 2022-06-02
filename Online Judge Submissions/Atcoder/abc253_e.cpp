#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define LIM 5005
#define nl "\n"
using namespace std;

ll n, m, k;
ll arr[LIM], dp[LIM][LIM];

ll getVal(ll idx, ll L, ll R)
{
    if(R < 0) return 0;
    if(L > m) return 0;
    return ((dp[idx][R] - dp[idx][L]) %mod + mod) %mod;
}

int main()
{
    cin >> n >> m >> k;

    for(ll i = 1; i <= m; i++)
        dp[1][i] = 1;

    for(ll i = 2; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            dp[i - 1][j] += dp[i - 1][j - 1];
            dp[i - 1][j] %= mod;
        }

        for(ll j = 1; j <= m; j++){
            dp[i][j] = (getVal(i - 1, 0, j - k) + getVal(i - 1, j + k - 1, m)) %mod;
            if(k == 0){
                dp[i][j] -= ((dp[i - 1][j] - dp[i - 1][j - 1]) %mod + mod) %mod;
                dp[i][j] = (dp[i][j] + mod) %mod;
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= m; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << nl;

    return 0;
}
