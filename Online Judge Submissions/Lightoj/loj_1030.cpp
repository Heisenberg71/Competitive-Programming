#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[105];
double dp[105];
double f()
{
    ll i, j, k, ans = 0;
    for(i = 1; i <= n; i++)
        dp[i] = 0;
    dp[n] = arr[n];
    for(i = n-1; i >= 1; i--){
        double tem = 0;
        for(j = i+1, k = 0; k < 6 and j <= n; j++, k++)
            tem += dp[j];
        dp[i] = (1.0*(k*arr[i]+tem))/k;
    }
    return dp[1];
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        printf("Case %lld: %0.10lf\n", cas++, f());
    }
    return 0;
}
