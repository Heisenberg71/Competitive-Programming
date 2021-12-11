#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;
vector <ll> v[100005];
ll dp[100005][2];
bool vis[100005];
void dfs(ll node)
{
    vis[node] = 1;
    ll white = 1, black = 1;
    for(ll i = 0; i < v[node].size(); i++){
        if(!vis[v[node][i]]){
            dfs(v[node][i]);
            white *= (dp[v[node][i]][0] + dp[v[node][i]][1]) % mod;
            black *= dp[v[node][i]][0] % mod;
            white %= mod;
            black %= mod;
        }
    }
    dp[node][0] = white;
    dp[node][1] = black;
}
int main()
{
    ll n, x, y, i;
    cin >> n;
    ll N = n-1;
    while(N--){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
//    for(i = 0; i < n; i++)
//        dp[0][i] = dp[1][i] = 1;
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%mod << endl;
    return 0;
}
