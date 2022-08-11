#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int n, m;
int prefTree[LIM], parent[LIM][25], depth[LIM];
vector <int> edge[LIM];

void dfs(int u, int pr)
{
    parent[u][0] = pr;
    if(pr != -1) depth[u] = 1 + depth[pr];
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr){
            dfs(v, u);
            prefTree[u] += prefTree[v];
        }
    }
}

void build()
{
    for(int i = 1; i <= 22; i++){
        for(int j = 1; j <= n; j++){
            if(parent[j][i - 1] != -1)
                parent[j][i] = parent[ parent[j][i - 1] ][i - 1];
        }
    }
}

int findLCA(int u, int v)    /// O(nlogn)
{
    if(depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];

    for(int i = 0; i <= 22; i++){
        if(diff & (1 << i))
            v = parent[v][i];
    }

    if(u == v) return v;

    for(int i = 22; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    memset(parent, -1, sizeof parent);
    dfs(1, -1);
    build();

    while(m--){
        int u, v;
        cin >> u >> v;
        int lca = findLCA(u, v);
        prefTree[u]++, prefTree[v]++;
        prefTree[lca]--;
        if(parent[lca][0] != -1) prefTree[ parent[lca][0] ]--;
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++)
        cout << prefTree[i] << " ";
    cout << nl;

    return 0;
}
