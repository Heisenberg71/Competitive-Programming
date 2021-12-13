#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, arr[1005], dp[1005][2];
ll f(ll pos, ll istaken)
{
    if(pos >= n) return 0;
    if(dp[pos][istaken] != -1) return dp[pos][istaken];
    ll a, b;
    if(pos == n-1){
        if(istaken) return 0;
        return arr[pos];
    }
    else{
        if(pos == 0) a = arr[pos] + f(pos+2, 1);
        else a = arr[pos] + f(pos+2,istaken);
    }
    b = f(pos+1, istaken);
    return dp[pos][istaken] = max(a,b);
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,0));
    }
    return 0;
}
