#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define inf 1000000009
#define LIM 10005
using namespace std;

int n, m, st, ed, p;
int dist[LIM], distInv[LIM];
vector <int> edge[LIM], edgeInv[LIM], cost[LIM], costInv[LIM];

void dijkstra(int src)
{
    for(int i = 0; i <= n; i++)
        dist[i] = inf;

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        for(int i = 0; i < edge[u.ss].size(); i++){
            int v = edge[u.ss][i];
            if(u.ff + cost[u.ss][i] < dist[v]){
                dist[v] = u.ff + cost[u.ss][i];
                pq.push({dist[v], v});
            }
        }
    }
//    cout << "here" << endl;
}

void dijkstraInv(int src)
{
    for(int i = 0; i <= n; i++)
        distInv[i] = inf;

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    distInv[src] = 0;

//    cout << "here1" << endl;

    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        for(int i = 0; i < edgeInv[u.ss].size(); i++){
            int v = edgeInv[u.ss][i];
            if(u.ff + costInv[u.ss][i] < distInv[v]){
                distInv[v] = u.ff + costInv[u.ss][i];
                pq.push({distInv[v], v});
            }
        }
    }
//        cout << "here" << endl;
}

int fun()
{
    dijkstra(st);
    dijkstraInv(ed);

    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < edge[i].size(); j++){
            int u = i, v = edge[i][j];
            if(dist[u] + distInv[v] + cost[i][j] > p) continue;
            ans = max(ans, cost[i][j]);
        }
    }

    return ans;
}

void reset()
{
    for(int i = 0; i <= n; i++){
        edge[i].clear(); edgeInv[i].clear();
        cost[i].clear(); costInv[i].clear();
    }
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &n, &m, &st, &ed, &p);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[u].pb(v), cost[u].pb(w);
            edgeInv[v].pb(u), costInv[v].pb(w);
        }
        printf("Case %d: %d\n", cas++, fun());

        reset();
    }

    return 0;
}
