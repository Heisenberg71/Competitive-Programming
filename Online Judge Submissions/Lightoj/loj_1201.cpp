#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll node, edge, dp[1005][2], pr[1005];
vector <ll> edg[1005];

ll dfs(ll u, ll prev)
{
    if(dp[u][prev] != -1) return dp[u][prev];

    ll tot = 1 && (prev == 0), tot2 = 0;
    for(ll i = 0; i < edg[u].size(); i++){
        ll v = edg[u][i];
        if(v == pr[u]) continue;
        pr[v] = u;
        if(prev == 0) tot += dfs(v, 1);
        tot2 += dfs(v, 0);
    }

    return dp[u][prev] = max(tot, tot2);
}

void reset()
{
    for(ll i = 0; i <= node; i++)
        edg[i].clear(), pr[i] = 0;
}

int main()
{
    ll t, cas = 1, i, x, y;
    cin >> t;
    while(t--){
        cin >> node >> edge;
        for(i = 0; i < edge; i++){
            cin >> x >> y;
            edg[x].pb(y);
            edg[y].pb(x);
        }
        memset(dp, -1, sizeof dp);
        ll ans = 0;
        for(i = 1; i <= node; i++){
            if(!pr[i]) ans += dfs(i, 0);
        }
        printf("Case %lld: %lld\n", cas++, ans);

        reset();
    }
    return 0;
}
