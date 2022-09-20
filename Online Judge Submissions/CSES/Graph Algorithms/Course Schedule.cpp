#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll, ll>
#define LIM 100005
#define nl '\n'
using namespace std;

int dist[LIM], par[LIM];
vector <int> edge[LIM], ans;

void dijkastra()
{
    priority_queue <pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(dist[u.ss] > u.ff) continue;
        for(int i = 0; i < edge[u.ss].size(); i++){
            int v = edge[u.ss][i];
            if(u.ff + 1 > dist[v]){
                dist[v] = u.ff + 1;
                par[v] = u.ss;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
   int n, m;

   cin >> n >> m;
   for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
   }

    dijkastra();
    if(dist[n]){
        ans.pb(n);
        int u = n;
        while(u != 1){
            u = par[u];
            ans.pb(u);
        }
        //ans.pb(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << nl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << nl;
    }
    else cout << "IMPOSSIBLE" << nl;


    return 0;
}
