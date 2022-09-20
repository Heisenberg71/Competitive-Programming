#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define LIM 2505
using namespace std;

vector <ll> edge[LIM], cost[LIM], ans;
ll dist[LIM], par[LIM], vis[LIM];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].pb(v); cost[u].pb(c);
    }

    for(int i = 1; i <= n; i++)
        par[i] = -1;

    int cycleNode;
    for(int i = 0; i < n; i++){
        cycleNode = -1;
        for(int j = 1; j <= n; j++){
            int u = j;
            for(int k = 0; k < edge[j].size(); k++){
                int v = edge[j][k];
                if(dist[u] + cost[u][k] < dist[v]){
                    dist[v] = dist[u] + cost[u][k];
                    par[v] = u;
                    cycleNode = v;
                }
            }
        }
    }

    if(cycleNode == -1) cout << "NO" << nl;
    else{
        cout << "YES" << nl;
        int u = cycleNode;
        while(!vis[u]){
            ans.pb(u);
            vis[u] = 1;
            u = par[u];
        }
        cout << u << " ";
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
            if(u == ans[i]) break;
        }
        cout << nl;
    }

    return 0;
}
