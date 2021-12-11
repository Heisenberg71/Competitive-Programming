#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, arr[100005], dp[100005];
ll f()
{
    ll ans = 0, i, j;
    for(i = n-1; i >= 0; i--){
        dp[i] = inf;
        if(i == n-1) dp[i] = 0;
        for(j = i+1; j < min(n,i+3); j++){
            dp[i] = min(dp[i],abs(arr[i]-arr[j])+dp[j]);
        }
    }
    return dp[0];
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << f() << endl;
    return 0;
}
