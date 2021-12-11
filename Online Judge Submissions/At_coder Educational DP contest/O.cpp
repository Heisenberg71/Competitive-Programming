#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll grid[22][22], dp[22][1<<22], n;
bool check(ll pos, ll mask){
    return (mask&(1<<pos));
}
ll mark(ll pos, ll mask){
    return (mask|(1<<pos));
}
ll f(ll i, ll mask)
{
    if(i == n) return 1;
    if(dp[i][mask] != -1) return dp[i][mask];
    ll ans = 0;
    for(ll j = 0; j < n; j++){
        if(!check(j,mask) and grid[i][j]){
            ans += f(i+1,mark(j,mask));
            ans %= mod;
        }
    }
    return dp[i][mask] = ans;
}
int main()
{
    ll i, j;
    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> grid[i][j];
    memset(dp,-1,sizeof(dp));
    cout << f(0,0) << endl;
    return 0;
}
