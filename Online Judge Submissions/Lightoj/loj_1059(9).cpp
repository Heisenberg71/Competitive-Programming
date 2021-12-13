#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
struct{
    ll from, to, cost;
}edges[105];
vector <ll> v[105], ed;
bool vis[105];
void dfs(ll node)
{
   vis[node] = 1;
   ed.pb(node);
   for(ll i = 0; i < v[node].size(); i++){
       if(!vis[v[node][i]]) dfs(v[node][i]);
   }
}
int main()
{
    ll t, n, x, y, wei, i, j, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++){
            cin >> x >> y >> wei;
            v[x].pb(y), v[y].pb(x);
            edges[i] = {x,y,wei};
        }
        dfs(1);
        ed.pb(ed[0]);
        ll ans = 0, mn = 1e9;
        for(i = 1; i < ed.size(); i++){
            ll found = 0;
            for(j = 0; j < n; j++){
                if(edges[j].from == ed[i-1] and edges[j].to == ed[i])
                    found = 1;
            }
            if(!found){
                for(j = 0; j < n; j++){
                    if(edges[j].from == ed[i] and edges[j].to == ed[i-1]){
                        ans += edges[j].cost;
                        break;
                    }
                }
            }
        }
        reverse(ed.begin(),ed.end());
        mn = min(mn,ans);
        ans = 0;
        for(i = 1; i < ed.size(); i++){
            ll found = 0;
            for(j = 0; j < n; j++){
                if(edges[j].from == ed[i-1] and edges[j].to == ed[i])
                    found = 1;
            }
            if(!found){
                for(j = 0; j < n; j++){
                    if(edges[j].from == ed[i] and edges[j].to == ed[i-1]){
                        ans += edges[j].cost;
                        break;
                    }
                }
            }
        }
        mn = min(mn,ans);
        //cout << mn << endl;
        printf("Case %lld: %lld\n", cas++, mn);
        ed.clear();
        for(i = 1; i <= n; i++)
            vis[i] = 0, v[i].clear();
    }
    return 0;
}
