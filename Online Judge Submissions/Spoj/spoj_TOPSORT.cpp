#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll vis[10005], iscycle;
vector <ll> res, v[10005];

bool cmp(ll a, ll b) { return a > b; }

void dfs(ll node)
{
    vis[node] = 1;
    for(ll i = 0; i < v[node].size(); i++){
        if(vis[v[node][i]] == 1) iscycle = 1;
        else if(vis[v[node][i]] == 0) dfs(v[node][i]);
    }
    vis[node] = 2;
    res.pb(node);
}

int main()
{
    ll n, k, x, y, i;
    //cin >> n >> k;
    scanf("%lld %lld", &n, &k);
    while(k--){
        //cin >> x >> y;
        scanf("%lld %lld", &x, &y);
        v[x].pb(y);
    }
    for(i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end(), cmp);
    for(i = n; i >= 1; i--)
        if(!vis[i]) dfs(i);
    if(iscycle){
        //cout << "Sandro fails." << endl;
        printf("Sandro fails.\n");
    }
    else{
        for(i = res.size()-1; i >= 0; i--)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
