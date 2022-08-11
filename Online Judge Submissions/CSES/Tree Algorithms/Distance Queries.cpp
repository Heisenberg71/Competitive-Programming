#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int parent[LIM][22], depth[LIM];
vector <int> edge[LIM];

void dfs(int u, int pr)
{
    if(pr != -1) depth[u] = depth[pr] + 1;
    parent[u][0] = pr;

    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr) dfs(v, u);
    }
}

void build(int n)
{
    int lg = log2(n) + 1;

    for(int k = 1; k <= lg; k++){
        for(int i = 1; i <= n; i++){
            if(parent[i][k - 1] != -1)
                parent[i][k] = parent[ parent[i][k - 1] ][k - 1];
        }
    }
}

int findLCA(int n, int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];

    int lg = log2(n) + 1;
    for(int i = 0; i <= lg; i++){
        if(diff&(1 << i))
            v = parent[v][i];
    }

    if(u == v) return v;

    for(int i = lg; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    memset(parent, -1, sizeof parent);
    dfs(1, -1);
    build(n);

    while(q--){
        int u, v;
        cin >> u >> v;
        int lca = findLCA(n, u, v);
        //cout << lca << nl;
        cout << abs(depth[u] - depth[lca]) + abs(depth[v] - depth[lca]) << nl;
    }

    return 0;
}
