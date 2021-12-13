#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll coins[105], fre[105], dp[100005], cnt[100005], n, m;
ll f()
{
    ll i, j, k;
    dp[0] = 1;
    for(i = 0; i < n; i++){
        memset(cnt,0,sizeof(cnt));
        for(j = 0; j <= m; j++){
            if(j >= coins[i] and !dp[j] and dp[j-coins[i]] and cnt[j-coins[i]]+1 <= fre[i]){
                dp[j] = 1;
                cnt[j] = cnt[j-coins[i]]+1;
            }
        }
    }
    ll coun = 0;
    for(i = 1; i <= m; i++)
        if(dp[i]) coun++;
    return coun;
}
int main()
{
    ll t, i, cas = 1;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%lld", &coins[i]);
        for(i = 0; i < n; i++)
            scanf("%lld", &fre[i]);
        for(i = 0; i <= m; i++)
            dp[i] = 0;
        printf("Case %lld: %lld\n", cas++, f());
    }
    return 0;
}
