#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll, ll>
#define LIM 100005
#define mod 1000000007
#define nl '\n'
using namespace std;

int n, m, dp[LIM];
vector <int> edge[LIM];

ll fun(int u)
{
    if(u == n) return 1;
    if(edge[u].size() == 0) return 0;
    if(dp[u] != -1) return dp[u];

    ll ans = 0;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        ans = (ans + fun(v)) %mod;
    }

    return dp[u] = ans;
}

int main()
{
   cin >> n >> m;
   for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
   }

    memset(dp, -1, sizeof dp);
    cout << fun(1) << nl;


    return 0;
}
