#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, arr[100005], dp[100005];
ll f(ll in)
{
    if(in >= n) return inf;
    if(in+1 == n) return 0;
    if(dp[in] != -1) return dp[in];
    return dp[in] = min(abs(arr[in]-arr[in+1])+f(in+1),abs(arr[in]-arr[in+2])+f(in+2));
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    cout << f(0) << endl;
    return 0;
}
