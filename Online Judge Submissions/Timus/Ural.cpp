#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[505][505];
ll f(ll last, ll tot)
{
    if(tot == 0) return 1;
    if(dp[last][tot] != -1) return dp[last][tot];
    ll ans = 0;
    for(ll i = last+1; i <= tot; i++)
        ans += f(i,tot-i);
    return dp[last][tot] = ans;
}
int main()
{
    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << f(0,n)-1 << endl;
    return 0;
}
