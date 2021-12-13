#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[20][20], dp[20][1<<16], n;
ll check(ll num, ll mask) {return mask&(1<<num);}
ll mark(ll num, ll mask) {return mask = mask|(1<<num);}
ll f(ll in, ll mask)
{
    if(in == n) return 0;
    if(dp[in][mask] != -1) return dp[in][mask];

    ll maxi = 0;
    for(ll i = 0; i < n; i++){
        if(!check(i,mask)){
            ll ans = arr[in][i] + f(in+1,mark(i,mask));
            maxi = max(maxi,ans);
        }
    }
    return dp[in][mask] = maxi;
}
int main()
{
    ll t, cas = 1, i, j;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> arr[i][j];
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n", cas++, f(0,0));
    }
    return 0;
}
