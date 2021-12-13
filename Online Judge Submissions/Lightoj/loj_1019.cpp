#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define ff first
#define ss second
using namespace std;
ll vis[105];
vector <ll> v[105], w[105];
priority_queue <pii, vector< pii >, greater<pii > > pq;
void dj(ll st)
{
    memset(vis,127,sizeof vis);
    pq.push({0,st});
    vis[st] = 0;
    while(!pq.empty()){
        ll top_val = pq.top().ff, top_ver = pq.top().ss; pq.pop();
        for(ll i = 0; i < v[top_ver].size(); i++){
            if(top_val+w[top_ver][i] < vis[v[top_ver][i]]){
                vis[v[top_ver][i]] = top_val+w[top_ver][i];
                pq.push({top_val+w[top_ver][i], v[top_ver][i]});
            }
        }
    }
}
int main()
{
    ll node, edges, wei, i, x, y, t, cas = 1;
    cin >> t;
    while(t--){
        cin >> node >> edges;
        for(i = 0; i < edges; i++){
            cin >> x >> y >> wei;
            v[x].pb(y), w[x].pb(wei);
            v[y].pb(x), w[y].pb(wei);
        }
        dj(1);
        for(i = 1; i <= node; i++)
            v[i].clear(), w[i].clear();
        printf("Case %lld: ", cas++);
        if(vis[node] > 1e9) cout << "Impossible" << endl;
        else cout << vis[node] << endl;
    }
    return 0;
}
