#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll dp[105][10005], n, coin[105], k;
int main()
{
    ll i, j, t, cas = 1;
    cin >> t;
    while(t--){
        scanf("%lld %lld", &n, &k);
        for(i = 0; i < n; i++)
            scanf("%lld", &coin[i]);
        for(i = 0; i <= k; i++)
            dp[n][i] = 0;
        for(i = 0; i < n; i++)
            dp[i][0] = 1;
        for(i = n; i >= 0; i--){
            for(j = 1; j <= k; j++){
                ll a, b;
                if(j < coin[i]) a = 0;
                else a = dp[i][j-coin[i]];
                if(i+1 == n) b = 0;
                else b = dp[i+1][j];
                dp[i][j] = (a+b)%mod;
            }
        }
        printf("Case %lld: %lld\n", cas++, dp[0][k]);
    }
    return 0;
}

