#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n, m, money[1005], vis[1005], tot, num_of_node;
vector <ll> v[1005];
void dfs(ll node)
{
    vis[node] = 1;
    tot += money[node];
    num_of_node++;
    for(ll i = 0; i < v[node].size(); i++){
        if(!vis[v[node][i]]) dfs(v[node][i]);
    }
}
int main()
{
    ll t, cas = 1, x, y, i;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll sum = 0;
        for(i = 1; i <= n; i++){
            cin >> money[i];
            sum += money[i];
        }
        while(m--){
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        ll f = 0;
        if(sum%n == 0) f = 1;
        for(i = 1; i <= n; i++){
            if(!vis[i]) dfs(i);
            if(tot*n != sum*num_of_node) f = 0;
            tot = num_of_node = 0;
        }
        printf("Case %lld: ", cas++);
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
        for(i = 1; i <= n; i++)
            v[i].clear(), vis[i] = 0;
    }
    return 0;
}
