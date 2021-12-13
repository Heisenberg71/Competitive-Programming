#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, grid[15][15], dp[1<<15+5];
bool check(ll pos, ll n){ return (bool)(n & (1<<pos));}
ll mark(ll pos, ll n){ return n = (n | (1<<pos));}
ll cost_cal(ll pos, ll mask)
{
    //if(cost[pos][mask] != -1) return cost[pos][mask];
    ll sum = 0;
    ll tem = mask;
    for(ll i = 0; tem != 0; i++){
        if(check(i,mask)) sum += grid[pos][i];
        tem /= 2;
    }
    //return cost[pos][mask] = sum;
    return sum;
}
ll f(ll mask)
{
    //cout << mask << endl;
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    ll i, ans = inf;
    for(i = 0; i < n; i++){
        if(!check(i,mask)){
            ans = min(ans,grid[i][i]+cost_cal(i,mask)+f(mark(i,mask)));
        }
    }
    return dp[mask] = ans;
}
int main()
{
    ll t, i, j, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> grid[i][j];
        memset(dp,-1,sizeof(dp));
        //memset(cost,-1,sizeof(cost));
        printf("Case %lld: %lld\n",cas++, f(0));
    }
    return 0;
}
