#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 300005
using namespace std;
ll vis[3][LIM], n;
vector <ll> v[LIM], w[LIM];
void dfs(ll node, ll forvis)
{
    for(ll i = 0; i < v[node].size(); i++){
        if(vis[forvis][v[node][i]] == -1){
            vis[forvis][v[node][i]] = vis[forvis][node] + w[node][i];
            dfs(v[node][i],forvis);
        }
    }
}
int main()
{
    ll t, cas = 1, x, y, wei, i;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n-1; i++){
            cin >> x >> y >> wei;
            v[x].pb(y); v[y].pb(x);
            w[x].pb(wei); w[y].pb(wei);
        }
        memset(vis,-1,sizeof(vis));
        vis[0][0] = 0;
        dfs(0,0);
        ll mx = 0, dia1, dia2;
        for(i = 0; i < n; i++){
            if(mx < vis[0][i]){
                mx = vis[0][i];
                dia1 = i;
            }
        }
        vis[1][dia1] = 0;
        dfs(dia1,1);
        mx = 0;
        for(i = 0; i < n; i++){
            if(mx < vis[1][i]){
                mx = vis[1][i];
                dia2 = i;
            }
        }
        vis[2][dia2] = 0;
        dfs(dia2,2);
        printf("Case %lld:\n", cas++);
        for(i = 0; i < n; i++){
            printf("%lld\n", max(vis[1][i],vis[2][i]));
            v[i].clear(), w[i].clear();
        }
    }
    return 0;
}
