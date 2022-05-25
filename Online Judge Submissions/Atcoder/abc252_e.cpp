/**

It is a collected code. My Code got TLE. I don't khow why. Idea was exactly the same.
The second one is my code.

*/

#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    vector<vector<ar<int, 3>>> adj(a+1);
    for (int i = 0; i < b; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back({y, c, i});
        adj[y].push_back({x, c, i});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll> d(a+1, 1e18);
    vector<int> p(a+1, -1);
    q.push({0, 1});
    d[1] = 0;
    while (q.size()) {
        auto [weight, v] = q.top();
        q.pop();
        if (d[v] != weight) continue;
        for (auto [u, w, idx] : adj[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                p[u] = idx;
                q.push({d[u], u});
            }
        }
    }
    for (int i = 2; i <= a; i++) {
        cout << p[i]+1 << " \n"[i==a];
    }
}


//<<--------------------------------------------------------------------------------------->>


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 200005 /// changed
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

vector <pll> saveEdge;
vector <int> edge[LIM], cost[LIM], edgeIdx[LIM];
ll dist[LIM];
int par[LIM], ans[LIM], parEdgeIdx[LIM];

void dj(int node)
{
    priority_queue <pli, vector< pli >, greater<pli > > pq;
    pli up;
    memset(dist, 127, sizeof dist);
    pq.push({0, node}); dist[node] = 0;
    while(!pq.empty()){
        up = pq.top(); pq.pop();
        for(int i = 0; i < edge[up.ss].size(); i++){
            int ver = edge[up.ss][i];
            int wei = cost[up.ss][i];
            if(wei+up.ff < dist[ver]){
                pq.push({wei+up.ff,ver});
                dist[ver] = wei+up.ff;
                par[ver] = up.ss;
                parEdgeIdx[ver] = edgeIdx[up.ss][i];
            }
        }
    }
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    int n, m;
    scanf("%d %d", &n, &m);
    for(ll i = 0; i < m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        saveEdge.pb({u, v});
        edge[u].pb(v); cost[u].pb(c); edgeIdx[u].pb(i);
        edge[v].pb(u); cost[v].pb(c); edgeIdx[v].pb(i);
    }
    dj(1);

    for(int i = 2; i <= n; i++)
        ans[ parEdgeIdx[i] ] = 1;

    for(int i = 0; i < m; i++){
        if(ans[i]) printf("%d ", i + 1);
    }


    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/


