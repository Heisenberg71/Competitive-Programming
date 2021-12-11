#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int parent[1005][22], depth[1005];
vector <int> edg[1005];

void dfs(int u, int pr) /// O(n)
{
    if(pr != -1)
        depth[u] = depth[pr] + 1;
    parent[u][0] = pr;

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

void init(int n)
{
    int lg = log2(n) + 1;
    for(int i = 0; i <= n; i++){
        edg[i].clear();
        depth[i] = 0;
        for(int j = 0; j <= lg; j++)
            parent[i][j] = -1;
    }
}
