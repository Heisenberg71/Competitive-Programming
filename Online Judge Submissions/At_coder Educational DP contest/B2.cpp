#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll n, k, arr[100005], dp[100005];
ll f()
{
    ll i, j;
    for(i = n-1; i >= 0; i--){
        dp[i] = inf; if(i+1 == n) dp[i] = 0;
        for(j = i+1; j < min(i+k+1,n); j++){
            dp[i] = min(dp[i],abs(arr[i]-arr[j])+dp[j]);
        }
    }
    return dp[0];
}
int main()
{
    ll i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << f() << endl;
    return 0;
}
