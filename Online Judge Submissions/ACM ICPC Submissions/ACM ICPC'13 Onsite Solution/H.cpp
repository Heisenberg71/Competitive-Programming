#include <bits/stdc++.h>
#define ll long long
#define LIM 30000005
using namespace std;

ll dp[LIM];

void precal()
{
    for(ll g = 1; g < LIM; g++){
        for(ll x = 1; x*g + g < LIM; x++){
            if(((x*g + g) ^ (x*g)) == g)
                dp[x*g + g]++;
        }
    }

    for(ll i = 1; i < LIM; i++)
        dp[i] += dp[i - 1];
}

int main()
{
    precal();

    ll t, n, cas = 1;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", cas++, dp[n]);
    }
    return 0;
}
