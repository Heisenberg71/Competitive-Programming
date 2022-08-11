#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define LIM 200005
using namespace std;

int vis[LIM], ans[LIM];
vector <int> edge[LIM];

void dfs(int u, int pr)
{
    vis[u] = 1 + vis[pr];
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(pr != v) dfs(v, u);
    }

}

int main()
{
    int n;

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    vis[0] = -1;
    dfs(1, 0);

    int u, mx = 0;
    for(int i = 1; i <= n; i++){
        //cout << i << " i:vis[i] " << vis[i] << nl;
        if(mx < vis[i]){
            mx = vis[i];
            u = i;
        }
    }

    memset(vis, 0, sizeof vis);
    vis[0] = -1;
    dfs(u, 0);

    for(int i = 1; i <= n; i++)
        ans[i] = vis[i];

    mx = 0;
    int v;
    for(int i = 1; i <= n; i++){
        if(mx < vis[i]){
            mx = vis[i];
            v = i;
        }
    }

    memset(vis, 0, sizeof vis);
    vis[0] = -1;
    dfs(v, 0);

    for(int i = 1; i <= n; i++)
        ans[i] = max(ans[i], vis[i]);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;

    return 0;
}
