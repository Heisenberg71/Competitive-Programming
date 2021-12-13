#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll dp[2005], status[2005];
vector <ll> v[2005];
void make_prime()
{
    ll i, j;
    for(i = 2; i < 1005; i++){
        if(!status[i]){
            for(j = i+i; j < 1005; j += i)
                v[j].pb(i), status[j] = 1;
        }
    }
}
int main()
{
    make_prime();
    ll t, cas = 1, i, j, from, to;
    cin >> t;
    while(t--){
        cin >> from >> to;
        memset(dp,127,sizeof dp);
        dp[from] = 0;
        for(i = from; i < to; i++){
            for(j = 0; j < v[i].size(); j++){
                ll tem = v[i][j];
                dp[i+tem] = min(dp[i+tem],dp[i]+1);
            }
        }
        if(dp[to] < to) printf("Case %lld: %lld\n", cas++, dp[to]);
        else printf("Case %lld: -1\n", cas++);
    }
    return 0;
}
