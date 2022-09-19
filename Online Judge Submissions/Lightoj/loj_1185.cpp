#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 105
using namespace std;

int n, m, vis[LIM];
vector <int> edge[LIM];

void dfs(int u, int col)
{
    vis[u] = col;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(vis[v] == -1) dfs(v, (col^1));
    }
}

bool isBiColorable()
{
    for(int u = 1; u <= n; u++){
        for(int i = 0; i < edge[u].size(); i++){
            if(vis[u] != -1 && vis[u] == vis[ edge[u][i] ]) return 0;
        }
    }
    return 1;
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            edge[u].pb(v), edge[v].pb(u);
        }
        memset(vis, -1, sizeof vis);
        dfs(1, 0);

        int tot = 0, one = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] != -1) tot++;
            if(vis[i] == 1) one++;
        }

        printf("Case %d: ", cas++);
        if(!isBiColorable()) printf("%d\n", tot);
        else{
            if(tot == 1) printf("0\n");
            else printf("%d\n", tot - one);
        }

        for(int i = 0; i <= n; i++)
            edge[i].clear();
    }

    return 0;
}
