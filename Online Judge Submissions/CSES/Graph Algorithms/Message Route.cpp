#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define nl '\n'
#define LIM 100005
using namespace std;

int n, m, vis[LIM];
vector <int> edge[LIM];

void dfs(int u, int col)
{
    vis[u] = col + 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!vis[v]) dfs(v, (col^1));
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

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, 0);
    }

    bool ans = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < edge[i].size(); j++){
            if(vis[i] == vis[ edge[i][j] ]) ans = 0;
        }
    }

    if(!ans){
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }

    for(int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << nl;

    return 0;
}
