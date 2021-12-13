#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;
vector <ll> v[1005];
ll ways[1005], subtree[1005], fact[1005], n;
bool root[1005];
void fac()
{
    fact[0] = 1;
    for(ll i = 1; i < 1005; i++)
        fact[i] = (i*fact[i-1])%mod;
}
ll bigmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = bigmod(a,b/2);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}
void dfs(ll node)
{
    ll up, down = 1, mult = 1;
    subtree[node] = 1;
    ways[node] = 1;
    for(ll i = 0; i < v[node].size(); i++){
        dfs(v[node][i]);
        mult *= ways[v[node][i]];
        mult %= mod;
        down *= bigmod(fact[subtree[v[node][i]]],mod-2);
        down %= mod;
        subtree[node] += subtree[v[node][i]];
    }
    ways[node] = (fact[subtree[node]-1]*down)%mod;
    ways[node] = (ways[node]*mult)%mod;
}
ll f()
{
    ll i;
    for(i = 1; i <= n; i++)
        if(!root[i]) break;
    dfs(i);
    return ways[i];
}
int main()
{
    fac();
    ll t, a, b, cas = 1, i;
    cin >> t;
    while(t--){
        cin >> n;
        ll N = n-1;
        while(N--){
            cin >> a >> b;
            v[a].pb(b);
            root[b] = 1;
        }
        printf("Case %lld: %lld\n", cas++, f());
        for(i = 1; i <= n; i++)
            v[i].clear(), root[i] = 0;
    }
    return 0;
}
