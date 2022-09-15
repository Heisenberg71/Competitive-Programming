#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define inf 1000006
using namespace std;

int n, m, q;
int dist[505][505], save[505];
pii dp[16][(1 << 16)];
bool vis[16][(1 << 16)];
vector <int> shop, edge[505], cost[505];

void reset()
{
    shop.clear();
    memset(save, 0, sizeof save);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++){
        edge[i].clear();
        cost[i].clear();
    }
}

pii fun(int pos, int mask)
{
    int u = shop[pos];

    if(__builtin_popcount(mask) == shop.size()) return {1, dist[u][n - 1]};

    if(vis[pos][mask]) return dp[pos][mask];

    pii ret = {1, dist[u][n - 1]};
    for(int i = 0; i < shop.size(); i++){
        int v = shop[i];
        if(!((1 << i)&mask)){
            if(dist[u][v] == inf) continue;
            pii val = fun(i, ((1 << i)|mask));
            val = {val.ff + 1, val.ss + dist[u][v]};
            if(ret.ff < val.ff) ret = val;
            else if(ret.ff == val.ff && ret.ss > val.ss) ret = val;
        }
    }

    vis[pos][mask] = 1;
    return dp[pos][mask] = ret;
}

void dijkstra(int src)
{
    for(int i = 0; i < n; i++)
        dist[src][i] = inf;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src][src] = 0;

    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        for(int i = 0; i < edge[u.ss].size(); i++){
            int v = edge[u.ss][i];
            if(u.ff + cost[u.ss][i] < dist[src][v]){
                dist[src][v] = u.ff + cost[u.ss][i];
                pq.push({dist[src][v], v});
            }
        }
    }
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &q);
        int cnt = 0;
        for(int i = 0; i < q; i++){
            int x;
            scanf("%d", &x);
            save[x]++;
            if(x > 0 && x < n - 1) shop.pb(x);
            else cnt++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = inf;
            }
        }

        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[u].pb(v), cost[u].pb(w);
        }

        dijkstra(0), dijkstra(n - 1);
        sort(shop.begin(), shop.end());
        for(int i = 0; i < shop.size(); i++)
            dijkstra(shop[i]);

        printf("Case %d: ",cas++);
        if(dist[0][n - 1] != inf){
            pii ans = {save[0] + save[n - 1], dist[0][n - 1]};
            for(int i = 0; i < shop.size(); i++){
                if(dist[0][ shop[i] ] == inf) continue;

                pii temp = fun(i, 0);
                temp.ff += save[0] + save[n - 1] - 1;
                temp.ss += dist[0][ shop[i] ];

                if(ans.ff < temp.ff) ans = temp;
                if(ans.ff == temp.ff && temp.ss < ans.ss) ans = temp;
            }
            printf("%d %d\n", ans.ff, ans.ss);
        }
        else printf("Impossible\n");

        reset();
    }

    return 0;
}

/**

1
8 9 5
4 7 1 5 3
4 7 94
2 1 3
3 7 31
0 4 29
7 2 6
5 0 88
7 5 53
3 1 9
5 6 76

*/
