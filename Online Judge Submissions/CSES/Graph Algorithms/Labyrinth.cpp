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
vector <pii> ans;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!vis[v]) dfs(v);
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
        if(!vis[i]){
            dfs(i);
            if(i != 1) ans.pb({1, i});
        }
    }

    cout << ans.size() << nl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].ff << " " << ans[i].ss << nl;

    return 0;
}
