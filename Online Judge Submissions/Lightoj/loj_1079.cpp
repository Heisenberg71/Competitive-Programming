#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define inf 1e9
using namespace std;
ll n, money[105], tot;
double prob[105], dp[105][10005], p;
double eval(ll pos, ll loot)
{
    if(pos == n){
        if(loot == 0) return 1.0;
        return 0.0;
    }
    return dp[pos][loot];
}
void f()
{
    ll i, j;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j <= tot; j++){
            if(j >= money[i])
                dp[i][j] = max((1.0-prob[i])*eval(i+1,j-money[i]),eval(i+1,j));
            else dp[i][j] = eval(i+1,j);
        }
    }
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> p >> n;
        tot = 0;
        for(i = 0; i < n; i++){
            scanf("%lld %lf", &money[i], &prob[i]);
            tot += money[i];
        }
        f();
        ll ans = 0;
        for(i = 0; i <= tot; i++)
            if(1.0-dp[0][i] < p+eps) ans = max(ans,i);
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
