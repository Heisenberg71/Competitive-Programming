#include <bits/stdc++.h>
#define ll long long
#define LIM 10005
#define mod 10000000000007
using namespace std;

ll dp[LIM][LIM];

void precal()
{
    ll i, j;
    for(i = 0; i < LIM; i++)
        dp[i][0] = 1;
    for(i = 1; i < LIM; i++){
        for(j = 1; j <= i; j++)
            dp[i][j] = (dp[i-1][j-1]*i) % mod;
    }

    for(i = 1; i < LIM; i++){
        for(j = 1; j <= i; j++){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
}

int main()
{
    precal();

    ll t, n, L, R, cas = 1;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld", &n, &L, &R);
        ll ans = (((dp[n*n][R] - dp[n*n][L-1]) % mod) + mod) % mod;
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}

