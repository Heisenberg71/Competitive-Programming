#define ll long long
#define pb push_back
#define LIM 5005
#define pll pair<ll, ll>
#define ff first
#define ss second
#define k 2 /// change the value of k to get k'th best shortest path

ll n;
vector <ll> vec[LIM+5], dis[LIM+5], cost[LIM+5];

void dj(ll st) // O(K*E*logV)
{
    priority_queue <pll, vector< pll >, greater<pll > > pq;
    pq.push({0, st});
    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(dis[u.ss].empty() || (dis[u.ss].size() < k && dis[u.ss].back() != u.ff)){
            dis[u.ss].pb(u.ff);
        }
        for(ll i = 0; i < vec[u.ss].size(); i++){
            ll v = vec[u.ss][i];
            ll wei = cost[u.ss][i];
            if(dis[v].size() == k) continue;
            pq.push({wei + u.ff, v});
        }
    }
}

void reset()
{
    for(ll i = 0; i <= n; i++){
        vec[i].clear();
        cost[i].clear();
        dis[i].clear();
    }
}
