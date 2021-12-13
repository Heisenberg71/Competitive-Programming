#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 10005
using namespace std;

int n, m, tim, dis[LIM], low[LIM], par[LIM];
vector <int> edg[LIM];
set <int> artpoint;

void dfs(int u)
{
    dis[u] = low[u] = tim++;
    int child = 0;
    //cout << "u: " << u << endl;
    for(int i = 0; i < edg[u].size(); i++){
        int v = edg[u][i];
        if(v != par[u]){
            if(dis[v]){
                low[u] = min(low[u], dis[v]);
            }
            else{
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dis[u] && u != 1)
                    artpoint.insert(u);
                child++;
            }
        }
    }
    //cout << "u: " << u << endl;
    //cout << "u: " << u << " low: " << low[u] << endl;
    if(u == 1 && child > 1) artpoint.insert(u);
}

int main()
{
    int t, cas = 1, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        while(m--){
            cin >> x >> y;
            edg[x].pb(y);
            edg[y].pb(x);
        }
        tim = 1;
        dfs(1);

        printf("Case %d: %d\n", cas++, artpoint.size());

        artpoint.clear();
        memset(par, 0, sizeof par);
        memset(dis, 0, sizeof dis);
        memset(low, 0, sizeof low);
        for(int i = 0; i <= n; i++)
            edg[i].clear();
    }
    return 0;
}

/**

123
13 15
1 2
2 3
3 4
4 5
4 6
6 12
12 13
13 6
1 8
8 9
9 10
10 11
11 9
6 7
7 3

*/
