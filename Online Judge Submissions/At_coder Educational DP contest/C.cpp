#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100005][5], n, dp[100005][5];
ll f(ll in, ll pre){
    if(in == n) return 0;
    if(dp[in][pre] != -1) return dp[in][pre];
    ll mx = 0;
    for(ll i = 0; i < 3; i++){
        if(i != pre) mx = max(mx,arr[in][i]+f(in+1,i));
    }
    return dp[in][pre] = mx;
}
int main()
{
    ll i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    memset(dp,-1,sizeof(dp));
    cout << f(0,5) << endl;
    return 0;
}
