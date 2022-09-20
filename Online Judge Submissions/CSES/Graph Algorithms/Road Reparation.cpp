#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define nl '\n'
using namespace std;

int par[LIM], sz[LIM];

int findP(int u)
{
    if(u == par[u]) return u;
    return par[u] = findP(par[u]);
}

void connect(int u, int v)
{
    if(sz[u] < sz[v]){
        par[u] = v;
        sz[v] += sz[u];
    }
    else{
        par[v] = u;
        sz[u] += sz[v];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int compo = n, maxSize = 1;
    for(int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u = findP(u);
        v = findP(v);
        if(u != v) {
            compo--;
            maxSize = max(maxSize, sz[u] + sz[v]);
            connect(u, v);
        }
        cout << compo << " " << maxSize << nl;
    }

    return 0;
}
