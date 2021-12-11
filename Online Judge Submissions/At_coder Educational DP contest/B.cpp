#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, k, arr[100005], dp[100005];
ll f(ll in)
{
    if(in+1 == n) return 0;
    if(dp[in] != -1) return dp[in];
    ll mn = inf; if(in+1 == n) mn = 0;
    for(ll i = in+1; i < min(in+k+1,n); i++)
        mn = min(mn,abs(arr[in]-arr[i]) + f(i));
    return dp[in] = mn;
}
int main()
{
    ll i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp,-1,sizeof dp);
    cout << f(0) << endl;
    return 0;
}
