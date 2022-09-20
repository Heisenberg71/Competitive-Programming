#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 100005
#define nl '\n'
using namespace std;

vector <int> edge[LIM], ans;
int vis[LIM], inDeg[LIM], imp;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(vis[v] == 0) dfs(v);
        else if(vis[v] == 1) imp = 1;
    }
    //cout << u << " ";
    ans.pb(u);
    vis[u] = 2;

}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    if(imp) cout << "IMPOSSIBLE" << nl;
    else{
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << nl;
    }

    return 0;
}
