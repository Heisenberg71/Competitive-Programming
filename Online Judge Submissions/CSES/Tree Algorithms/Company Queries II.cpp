#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int parent[LIM][22], depth[LIM];
vector <int> edg[LIM];

void dfs(int u, int pr) /// O(n)
{
    if(pr != -1)
        depth[u] = depth[pr] + 1;
    parent[u][0] = pr;

//    cout << u << " " << pr << " " << depth[u] << " " << depth[pr] << nl;

    for(int i = 0; i < edg[u].size(); i++){
        int v = edg[u][i];
        if(v != pr) dfs(v, u);
    }

}

void build(int n)   /// O(nlogn)
{
    int lg = log2(n) + 1;

    for(int k = 1; k <= lg; k++){
        for(int i = 1; i <= n; i++){
            if(parent[i][k-1] != -1)
                parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }

}

int findLCA(int n, int u, int v)    /// O(nlogn)
{
    if(depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];

    int lg = log2(n) + 1;
    for(int i = 0; i <= lg; i++){
        if(diff & (1 << i))
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

    memset(parent, -1, sizeof parent);

    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> parent[i][0];
        edg[i].pb(parent[i][0]);
        edg[ parent[i][0] ].pb(i);
    }

    dfs(1, -1);
    build(n);

//    for(int i = 1; i <= n; i++)
//        cout << i << " " << depth[i] << nl;

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << findLCA(n, u, v) << nl;
    }

    return 0;
}
