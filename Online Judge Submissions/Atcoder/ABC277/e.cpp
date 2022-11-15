
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
using namespace std;

int n, m, k;
int vis[LIM][2], mark[LIM];
vector <pii> edge[LIM];

void bfs()
{
    memset(vis, 127, sizeof vis);
    vis[1][1] = 0;
    queue <pii> q;
    q.push({1, 1});
    if(mark[1]){
        vis[1][0] = 0;
        q.push({1, 0});
    }
    while(!q.empty()){
        pii u = q.front(); q.pop();
        //cout << u.ff << " " << u.ss << " " << vis[u.ff][u.ss] <<  nl;
        for(int i = 0; i < edge[ u.ff ].size(); i++){
            pii v = edge[u.ff][i];
            if(u.ss == v.ss && vis[u.ff][u.ss] + 1 < vis[v.ff][v.ss]){
                vis[v.ff][v.ss] = 1 + vis[u.ff][u.ss];
                q.push(v);
            }
            if(mark[u.ff] && u.ss != v.ss && vis[u.ff][u.ss] + 1 < vis[v.ff][v.ss]){
                vis[v.ff][v.ss] = 1 + vis[u.ff][u.ss];
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, a;
        cin >> u >> v >> a;
        edge[u].pb({v, a});
        edge[v].pb({u, a});
    }

    for(int i = 0; i < k; i++){
        int u;
        cin >> u;
        mark[u] = 1;
    }

    bfs();
    int ans = min(vis[n][0], vis[n][1]);
    if(ans < 400005) cout << ans << nl;
    else cout << -1 << nl;

    return 0;
}
