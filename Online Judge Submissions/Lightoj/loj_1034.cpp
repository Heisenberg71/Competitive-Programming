#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 10005
using namespace std;

int n, m;
bool vis[LIM];
vector <int> edg[LIM];
stack <int> stk;

void dfs(int u, int ty)
{
    vis[u] = 1;
    for(int i = 0; i < edg[u].size(); i++){
        int v = edg[u][i];
        if(!vis[v]) dfs(v, ty);
    }
    if(ty) stk.push(u);
}

void reset()
{
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        edg[i].clear();
    }
}

int main()
{
    int i, j, x, y, t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i = 0; i < m; i++){
            cin >> x >> y;
            edg[x].pb(y);
        }
        for(i = 1; i <= n; i++)
            if(!vis[i]) dfs(i, 1);
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        while(!stk.empty()){
            int u = stk.top(); stk.pop();
            if(!vis[u]) dfs(u, 0), cnt++;
        }
        printf("Case %d: %d\n", cas++, cnt);

        reset();
    }

    return 0;
}
