#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll n, k, dp[5][15005], tot;
ll f()
{
    ll i, j;
    dp[0][0] = 1;
    for(i = 0; i <= tot; i++)
        dp[0][i] = 1;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= tot; j++){
            if(j >= k+1) dp[i%2][j] = (dp[(i-1)%2][j-1]-dp[(i-1)%2][j-k-1]+mod)%mod;
            else dp[i%2][j] = dp[(i-1)%2][j-1]%mod;
        }
        for(j = 1; j <= tot; j++){
            dp[i%2][j] += dp[i%2][j-1];
            dp[i%2][j] %= mod;
        }
        dp[0][0] = 0;
    }
//    for(i = 0; i <= 1; i++){
//        for(j = 0; j <= tot; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//    }
    return (dp[n%2][tot]-dp[n%2][tot-1]+mod)%mod;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> k >> tot;
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
