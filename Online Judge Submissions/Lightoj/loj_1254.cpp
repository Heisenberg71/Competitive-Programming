#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define inf 1000000009
using namespace std;

int n, m;
int dist[105][105], city[105];
vector <int> edge[105], cost[105];

struct Node{
    int currentCost, currentFuel, node;
};

void reset(int n)
{
    for(int i = 0; i < n; i++)
        edge[i].clear(), cost[i].clear();
}

bool operator < (Node A, Node B)
{
    if(A.currentCost == B.currentCost) return A.currentFuel < B.currentFuel;
    else return A.currentCost > B.currentCost;
}

int dijkstra(int src, int ed, int capa)  ///O(E * log(v) * capa)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= capa; j++)
            dist[i][j] = inf;
    }

    priority_queue <Node> pq;
    pq.push({0, 0, src});
    while(!pq.empty()){
        Node u = pq.top(); pq.pop();
        if(ed == u.node) return u.currentCost;
        for(int i = 0; i < edge[u.node].size(); i++){
            int v = edge[u.node][i];
            for(int j = 0; j + u.currentFuel <= capa; j++){
                int newFuel = j + u.currentFuel - cost[u.node][i];
                int newCost = u.currentCost + j*city[u.node];
                if(newFuel >= 0 && newCost < dist[v][newFuel]){
                    dist[v][newFuel] = newCost;
                    pq.push({newCost, newFuel, v});
                }
            }
        }
    }

    return -1;
}

int main()
{
    int t, cas = 1, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &city[i]);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[u].pb(v), edge[v].pb(u);
            cost[u].pb(w), cost[v].pb(w);
        }
        printf("Case %d:\n", cas++);
        scanf("%d", &q);
        while(q--){
            int st, ed, capa;
            scanf("%d %d %d", &capa, &st, &ed);
            int ans = dijkstra(st, ed, capa);
            if(ans == -1) printf("impossible\n");
            else printf("%d\n", ans);
        }
        reset(n);
    }
    return 0;
}
