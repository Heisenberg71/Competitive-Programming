#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define ff first
#define ss second
#define LIM 100005
#define nl '\n'
using namespace std;

ll dist[LIM][15];
vector <ll> edge[LIM], cost[LIM];

void dijkastra()
{
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    memset(dist, 127, sizeof dist);
    dist[1][0] = 0;

    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(dist[u.ss][9] < u.ff) continue;
        for(int i = 0; i < edge[u.ss].size(); i++){
            int v = edge[u.ss][i];
            ll d = u.ff + cost[u.ss][i];
            for(int pos = 0; pos < 10; pos++){
                if(d < dist[v][pos]){
                    for(int j = 9; j > pos; j--)
                        dist[v][j] = dist[v][j - 1];
                    dist[v][pos] = d;
                    pq.push({d, v});
                    break;
                }
            }
        }
    }
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].pb(v); cost[u].pb(c);
    }

    dijkastra();

    for(int i = 0; i < k; i++)
        cout << dist[n][i] << " ";
    cout << nl;

    return 0;
}
