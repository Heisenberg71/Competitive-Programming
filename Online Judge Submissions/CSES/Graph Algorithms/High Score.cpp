#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000000018
#define LIM 300005
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

int n, m;
ll dist[2][LIM];
vector <ll> edge[2][LIM], cost[2][LIM];

void dj(int idx, int st)
{
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({0, st});
    dist[idx][st] = 0;

    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(dist[idx][u.ss] < u.ff) continue;
        for(int i = 0; i < edge[idx][u.ss].size(); i++){
            int v = edge[idx][u.ss][i];
            if(dist[idx][u.ss] + cost[idx][u.ss][i] < dist[idx][v]){
                dist[idx][v] = dist[idx][u.ss] + cost[idx][u.ss][i];
                pq.push({dist[idx][v], v});
            }
        }
    }
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[0][u].pb(v); cost[0][u].pb(c);
        edge[1][v].pb(u); cost[1][v].pb(c);
    }

    memset(dist, 127, sizeof dist);
    dj(0, 1);
    dj(1, n);

//    for(int i = 1; i <= n; i++)
//        cout << dist[0][i] << " " << dist[1][i] << nl;

    ll ans = MAXX;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < edge[0][i].size(); j++){
            int u = i;
            int v = edge[0][i][j];
            if(dist[0][u] == MAXX || dist[1][v] == MAXX) continue;
            ans = min(ans, cost[0][u][j]/2 + dist[0][u] + dist[1][v]);
        }
    }
    cout << ans << nl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. READ PROBLEM STATEMENT CAREFULLY.
    2. LOOK SPECIAL CASE (LIKE, N = 1).
    3. LOOK FOR OVERFLOW.
    4. LOOK FOR OUT OF BOUNDS.
    5. DO NOT STUCK WITH A SINGLE APPROACH.
    6. THINK OUT OF THE BOX.
**/
