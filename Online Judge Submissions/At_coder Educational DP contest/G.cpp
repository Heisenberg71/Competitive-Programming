#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> v[100005];
ll vis[100005];
ll dfs(ll x)
{
    if(vis[x] != -1) return vis[x];
    ll mx = 0;
    for(ll i = 0; i < v[x].size(); i++)
        mx = max(mx,1+dfs(v[x][i]));
    return vis[x] = mx;
}
int main()
{
    ll n, m, x, y, i;
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        v[x].pb(y);
    }
    memset(vis,-1,sizeof vis);
    for(i = 1; i <= n; i++)
        if(vis[i] == -1) dfs(i);
    ll mx = 0;
    for(i = 1; i <= n; i++)
        mx = max(mx,vis[i]);
    cout << mx << endl;
    return 0;
}
