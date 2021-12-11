#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, capa, v[105], w[105], sum, dp[5][100005];
ll f()
{
    ll i, j;
    for(i = 0; i <= sum; i++){
        dp[n%2][i] = inf;
    }
    dp[n%2][0] = 0;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j <= sum; j++){
            ll a = inf, b = inf;
            if(j >= v[i])
                a = w[i]+dp[(i+1)%2][j-v[i]];
            b = dp[(i+1)%2][j];
            dp[i%2][j] = min(a,b);
        }
    }
    ll ans = 0;
    for(i = 0; i <= sum; i++){
        if(dp[0][i] <= capa) ans = max(ans,i);
    }
    return ans;
}
int main()
{
    ll i, j;
    cin >> n >> capa;
    for(i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    cout << f() << endl;
    return 0;
}
