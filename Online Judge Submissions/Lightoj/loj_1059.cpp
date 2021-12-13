#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 100005
using namespace std;

int n, m, air, pr[LIM], vis[LIM], cost, port;

struct abc{
    int w, x, y;
};

vector <int> ver[LIM], wei[LIM];
vector <abc> edg;

bool cmp(abc x, abc y)
{
    return x.w < y.w;
}

void reset()
{
    edg.clear();
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
        ver[i].clear(); wei[i].clear();
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < ver[u].size(); i++){
        int v = ver[u][i];
        if(!vis[v]){
            dfs(v);
            if(wei[u][i] >= air) cost += air, port++;
            else cost += wei[u][i];
        }
    }
}

int findP(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);
    if(u != v){
        pr[u] = v;
    }
}

void MST()
{
    int i, j;

    for(i = 1; i <= n; i++)
        pr[i] = i;

    sort(edg.begin(), edg.end(), cmp);

    for(i = 0; i < edg.size(); i++){
        int u = findP(edg[i].x);
        int v = findP(edg[i].y);
        if(u != v){
            connect(u, v);
            ver[edg[i].x].pb(edg[i].y); wei[edg[i].x].pb(edg[i].w);
            ver[edg[i].y].pb(edg[i].x); wei[edg[i].y].pb(edg[i].w);
        }
    }

    cost = port = 0;
    for(i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cost += air;
            port++;
        }
    }

    printf("%d %d\n", cost, port);
}

int main()
{
    int t, cas = 1, i, x, y, cost;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &air);
        while(m--){
            scanf("%d %d %d", &x, &y, &cost);
            edg.pb({cost, x, y});
        }
        printf("Case %d: ", cas++);
        MST();

        reset();
    }

    return 0;
}
