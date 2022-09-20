#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define ff first
#define ss second
#define nl '\n'
using namespace std;

int par[LIM];
vector < pair<ll, pair<ll, ll> > > edge;

int findP(int u)
{
    if(u == par[u]) return u;
    return par[u] = findP(par[u]);
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge.pb({c, {u, v}});
    }

    for(int i = 1; i <= n; i++)
        par[i] = i;

    sort(edge.begin(), edge.end());

    ll ans = 0, take = 0;
    for(int i = 0; take < n - 1 && i < m; i++){
        int cost = edge[i].ff;
        int u = edge[i].ss.ff; u = findP(u);
        int v = edge[i].ss.ss; v = findP(v);
        if(findP(u) != findP(v)){
            ans += cost;
            par[u] = v;
            take++;
        }
    }

    if(take == n - 1) cout << ans << nl;
    else cout << "IMPOSSIBLE" << nl;

    return 0;
}
