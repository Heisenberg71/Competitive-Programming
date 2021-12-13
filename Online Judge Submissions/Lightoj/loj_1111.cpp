#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll vis[1005], home[1005], go[1005], curr;
vector <ll> v[1005];
void dfs(ll node)
{
    vis[node] = 1;
    go[node] += home[curr];
    for(ll i = 0; i < v[node].size(); i++){
        if(!vis[v[node][i]]){
            dfs(v[node][i]);
        }
    }
}
int main()
{
    ll t, cas = 1, k, n, m, x, y, i, j;
    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        for(i = 0; i < k; i++){
            scanf("%lld", &x);
            home[x]++;
        }
        for(i = 0; i < m; i++){
            scanf("%lld %lld", &x, &y);
            v[x].pb(y);
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++)
                vis[j] = 0;
            curr = i;
            dfs(i);
        }
        ll cnt = 0;
        for(i = 1; i <= n; i++){
            //cout << go[i] << endl;
            if(go[i] == k) cnt++;
            go[i] = 0; home[i] = 0;
            v[i].clear();
        }
        printf("Case %lld: %lld\n", cas++, cnt);
    }
    return 0;
}
