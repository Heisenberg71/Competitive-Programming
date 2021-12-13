#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define LIM 10005
using namespace std;
ll dis[LIM], vis[LIM], par[LIM], low[LIM], cnt, n;
vector <ll> ver[LIM];
vector <pair<ll,ll> > ans;
bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.ff == b.ff) return a.ss < b.ss;
    return a.ff < b.ff;
}
void dfs(ll u)
{
    dis[u] = low[u] = cnt++;
    for(ll i = 0; i < ver[u].size(); i++){
        ll v = ver[u][i];
        if(v != par[u]){ //cout << u << " nodes " << v << " " << par[u] << endl;
            if(vis[v] == 0){
                par[v] = u;
                vis[v] = 1;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(vis[v] == 1){
                low[u] = min(low[u], dis[v]);
            }
            if(dis[u] < low[v]) ans.pb({min(u,v), max(u,v)});
        }
    }
    vis[u] = 2;
}
int main()
{
    ll t, cas = 1, num, from, to, i, j;
    char ch;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++){
            scanf("%lld (%lld)", &from, &num);
            while(num--){
                scanf("%lld", &to);
                ver[from].pb(to);
            }
        }
        memset(vis,0,sizeof vis);
        memset(par,0,sizeof par);
        cnt = 0;
        for(i = 0; i < n; i++){
            if(!vis[i]) vis[i] = 1, par[i] = -1, dfs(i);
        }
//        cout << "par: " << endl;
//        for(i = 0; i < n; i++)
//            cout << par[i] << " ";
//        cout << ":par" << endl;
        sort(ans.begin(),ans.end(),cmp);
        printf("Case %lld:\n%lld critical links\n", cas++, (ll)ans.size());
        for(i = 0; i < ans.size(); i++)
            printf("%lld - %lld\n", ans[i].ff, ans[i].ss);
        ans.clear();
        for(i = 0; i < n; i++)
            ver[i].clear();
    }
    return 0;
}
