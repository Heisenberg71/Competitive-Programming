#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define ff first
#define ss second
#define pb push_back
#define inf 100000
#define piii pair<pair<int, int>, int >
using namespace std;

vector <int> edge[LIM], cost[LIM];
int n, m, x, st, ed;
int vis[LIM], prv[LIM];

void dj(int dis, int node)
{
    priority_queue <piii, vector< piii >, greater< piii > > pq;
    piii up;
    for(int i = 1; i <= n; i++)
        vis[i] = inf;
    pq.push({{dis, x}, node}); vis[node] = 0;
    prv[node] = x;
    while(!pq.empty()){
        up = pq.top(); pq.pop();
        for(int i = 0; i < edge[ up.ss ].size(); i++){
            int ver = edge[ up.ss ][i];
            int wei = cost[ up.ss ][i];

            if(up.ff.ss < wei) continue;

            if(wei + up.ff.ff < vis[ver]){
                vis[ver] = wei + up.ff.ff;
                prv[ver] = max(prv[ver], __gcd(up.ff.ss, wei));
                pq.push({{vis[ver], __gcd(up.ff.ss, wei)}, ver});
            }
            else if(prv[ver] < __gcd(up.ff.ss, wei)){
                prv[ver] = __gcd(up.ff.ss, wei);
                pq.push({{up.ff.ff + wei, prv[ver]}, ver});
            }
        }
    }
}

void reset()
{
    for(int i = 1; i <= n; i++){
        edge[i].clear();
        cost[i].clear();
        prv[i];
    }
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        while(m--){
            int u, v, c;
            cin >> u >> v >> c;
            edge[u].pb(v), edge[v].pb(u);
            cost[u].pb(c), cost[v].pb(c);
        }
        cin >> st >> ed >> x;

        dj(0, st);

        printf("Case %d: ", cas++);
        if(vis[ed] != inf) printf("%d\n", vis[ed]);
        else printf("impossible\n");

        reset();
    }

    return 0;
}

/**

2
node: 6  edge: 7
(u, v, cost)
1 2 4
1 4 1
2 3 2
2 4 4
3 6 4
4 5 4
5 6 4
(src, dest, X) = (1 6 12)

5 5
1 2 4
2 3 1
3 5 3
1 4 6
4 5 10
1 5 12


*/
