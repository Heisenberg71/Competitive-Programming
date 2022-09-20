#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define inf 1000000000000015
#define nl '\n'
#define LIM 2505
using namespace std;

ll vis[LIM], vis2[LIM], dist[LIM];
vector <ll> edge[LIM], cost[LIM], revEdge[LIM];

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!vis[v]) dfs(v);
    }
}

void dfs2(int u)
{
    vis2[u] = 1;
    for(int i = 0; i < revEdge[u].size(); i++){
        int v = revEdge[u][i];
        if(!vis2[v]) dfs2(v);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].pb(v); cost[u].pb(c);
        revEdge[v].pb(u);
    }

    dfs(1);
    dfs2(n);

    for(int i = 0; i <= n; i++){
        dist[i] = -inf;
    }

    dist[1] = 0;
    bool posCycle = 0;
    for(int i = 0; i < n; i++){
        posCycle = 0;
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < edge[j].size(); k++){
                if(vis[j] && vis2[j] && dist[ edge[j][k] ] < dist[j] + cost[j][k])
                    posCycle = 1;
                dist[ edge[j][k] ] = max(dist[ edge[j][k] ], dist[j] + cost[j][k]);
            }
        }
    }

    if(!posCycle)cout << dist[n] << nl;
    else cout << -1 << nl;

    return 0;
}
