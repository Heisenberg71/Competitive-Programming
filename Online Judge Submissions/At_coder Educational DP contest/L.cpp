#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[3005], dp[3005][3005];
ll f(ll L, ll R)
{
    if(L == R) return arr[L];
    if(dp[L][R] != -1) return dp[L][R];
    ll a = arr[L] - f(L+1,R);
    ll b = arr[R] - f(L,R-1);
    return dp[L][R] = max(a,b);
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    cout << f(0,n-1) << endl;
    return 0;
}
