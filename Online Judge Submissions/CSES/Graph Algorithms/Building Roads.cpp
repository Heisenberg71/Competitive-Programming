#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define nl '\n'
#define LIM 100005
using namespace std;

int n, m, vis[LIM], par[LIM];
vector <int> edge[LIM], ans;

void bfs()
{
    queue <int> q;
    vis[n] = 1;
    q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                par[v] = u;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    bfs();

    if(!vis[1]){
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }

    int u = 1;
    while(u != n){
        ans.pb(u);
        u = par[u];
    }
    ans.pb(n);

    cout << ans.size() << nl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << nl;

    return 0;
}
