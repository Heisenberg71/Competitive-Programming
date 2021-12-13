#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, arr[15], dp[15][15];
ll f(ll in, ll prev)
{
    if(in == k) return 1;
    if(dp[in][prev] != -1) return dp[in][prev];
    ll sum = 0, i;
    if(in == 0 and prev == 0){
        for(i = 0; i < n; i++)
            sum += f(in+1,i);
    }
    else{
        for(i = prev; i < n and arr[prev]+2 >= arr[i]; i++)
            sum += f(in+1,i);
        for(i = prev-1; i >= 0 and arr[i]+2 >= arr[prev]; i--)
            sum += f(in+1,i);
    }
    return dp[in][prev] = sum;
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,0));
    }
    return 0;
}
